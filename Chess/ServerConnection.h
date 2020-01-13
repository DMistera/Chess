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

#include <vector>

using namespace sf;

class ServerConnection
{
public:
	ServerConnection(String node);
	~ServerConnection();
	bool init();
	void write(String msg);
	int readAsync(std::function<void(String)> callback);
	void unreadAsync(int index);
	String readSync();
private:
	void read();
	bool tryToConnect(PCSTR addres);
	void readAsyncThread();
	SOCKET m_socket;
	static const int READ_BUF_LENGTH = 5;
	std::thread* m_readThread;
	String m_node;
	bool m_readyWait;
	std::vector<std::function<void(String)>> m_callbacks;
};

