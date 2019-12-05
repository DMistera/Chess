#include "OnlinePlayer.h"



OnlinePlayer::OnlinePlayer(Side side, ServerConnection* connection, std::function<void(String)> onError) : Player(side)
{
	m_connection = connection;
	m_onError = onError;
}


OnlinePlayer::~OnlinePlayer()
{
}

Move * OnlinePlayer::requestMove(GameState& state)
{
	try {
		return new Move(m_connection->read());
	}
	catch (std::exception e) {
		m_onError("Opponent \ndisconnected!");
		return nullptr;
	}
}
