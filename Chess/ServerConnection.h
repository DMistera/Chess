#pragma once

#define WIN32_LEAN_AND_MEAN


#include <winsock2.h>
#include <Ws2tcpip.h>
#include <iostream>
#include <SFML/System/String.hpp>
#include <functional>
#include <thread>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace sf;

class ServerConnection
{
public:
	ServerConnection();
	~ServerConnection();
	bool init();
	void write(String msg);
	String read();
	void readAsync(std::function<void(String)> callback);
private:
	bool tryToConnect(PCSTR addres);
	void readAsyncThread(std::function<void(String)> callback);
	SOCKET m_socket;
	static const int READ_BUF_LENGTH = 5;
	std::thread* m_readThread;
};

