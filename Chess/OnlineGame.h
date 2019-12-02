#pragma once

#include "Game.h"
#include "ServerConnection.h"
#include "OnlinePlayer.h"

class OnlineGame : public Game
{
public:
	OnlineGame(ServerConnection* serverConnection, Side localSide);
	~OnlineGame();
private:
	ServerConnection* m_connection;
	Side m_localSide;

	// Inherited via Game
	virtual Player * createWhitePlayer() override;
	virtual Player * createBlackPlayer() override;
	std::function<void(String)> onlinePlayerErrorCallback();
};

