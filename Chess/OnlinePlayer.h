#pragma once

#include "Player.h"
#include "ServerConnection.h"
#include <sstream>

class OnlinePlayer : public Player
{
public:
	OnlinePlayer(Side side, ServerConnection* connection, std::function<void(String)> onError);
	~OnlinePlayer();
	virtual Move * requestMove(GameState& state) override;
private:
	String moveToString(Move* move);
	Move* stringToMove(String string);
	ServerConnection* m_connection; 
	std::function<void(String)> m_onError;
};

