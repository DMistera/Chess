#include "ServerConnection.h"

ServerConnection::ServerConnection(String node)
{
	m_node = node;
}

bool ServerConnection::init()
{
	if (tryToConnect(m_node.toAnsiString().c_str())) {
		std::cout << "Connected to " << m_node.toAnsiString() << std::endl;
		return true;
	}
	return false;
}

void ServerConnection::write(String msg)
{
	std::string str = msg.toAnsiString(); // For some reason it doesnt work without assigning to variable first
	const char* sendBuf = str.c_str();
	std::cout << "Sending " << sendBuf << std::endl;
	int iResult = send(m_socket, sendBuf, (int)strlen(sendBuf), 0);
	if (iResult == SOCKET_ERROR) {
		std::cerr << "Send failed, error code " << WSAGetLastError() << std::endl;
	}
}

void ServerConnection::read()
{
	char receiveBuf[READ_BUF_LENGTH];
	m_readyWait = true;
	std::cout << "Reading" << std::endl;
	int iResult = recv(m_socket, receiveBuf, READ_BUF_LENGTH, 0);
	m_readyWait = false;
	std::cout << iResult << std::endl;
	if (iResult < 0)
		std::cerr << "Receive failed, error code " << WSAGetLastError() << std::endl;
	else if (iResult == 0)
		std::cerr << "Connection closed" <<  std::endl;
	std::cout << "Message received: " << String(receiveBuf).toAnsiString() << std::endl;
	String result = String(receiveBuf);
	for (auto callback : m_callbacks) {
		callback(result);
	}
	m_callbacks.clear();
}

int ServerConnection::readAsync(std::function<void(String)> callback)
{
	m_callbacks.push_back(callback);
	if (!m_readyWait) {
		m_readThread = new std::thread(&ServerConnection::readAsyncThread, this);
	}
	return m_callbacks.size() - 1;
}

void ServerConnection::unreadAsync(int index)
{
	m_callbacks.erase(m_callbacks.begin() + index);
}

String ServerConnection::readSync()
{
	String result = "";
	readAsync([&](String r) {
		result = r;
	});
	while (result.toAnsiString().length() == 0);
	return result;
}

bool ServerConnection::tryToConnect(PCSTR addres)
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::cerr << "WSAStartup failed, error code " << iResult << std::endl;
		return false;
	}
	addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	struct addrinfo *result;
	iResult = getaddrinfo(addres, "1234", &hints, &result);
	if (iResult != 0) {
		std::cerr << "getaddrinfo failed, error code " << iResult << std::endl;
		WSACleanup();
		return false;
	}

	struct addrinfo *ptr;
	m_socket = INVALID_SOCKET;
	for (ptr = result; ptr != nullptr; ptr = ptr->ai_next) {
		m_socket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (m_socket == INVALID_SOCKET) {
			std::cerr << "socket failed, error code " << WSAGetLastError() << std::endl;
			WSACleanup();
			return false;
		}

		iResult = connect(m_socket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(m_socket);
			m_socket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (m_socket == INVALID_SOCKET) {
		std::cerr << "Failed to connect to server!" << std::endl;
		WSACleanup();
		return false;
	}
	return true;
}

void ServerConnection::readAsyncThread()
{
	read();
}


ServerConnection::~ServerConnection()
{
	closesocket(m_socket);
	WSACleanup();
}
