#pragma once

#include "Player.h"
#include "ServerConnection.h"
class OnlinePlayer : public Player
{
public:
	OnlinePlayer(Side side, ServerConnection* connection, std::function<void(String)> onError);
	~OnlinePlayer();
	virtual Move * requestMove(GameState& state) override;
private:
	ServerConnection* m_connection; 
	std::function<void(String)> m_onError;
};

