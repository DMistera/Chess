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
	if (state.getLastMove()) {
		m_connection->write(moveToString(state.getLastMove()));
	}
	Move* result = stringToMove(m_connection->read());
	if (!result) {
		m_onError("Opponent \ndisconnected!");
	}
	return result;
}

String OnlinePlayer::moveToString(Move* move)
{
	Field start = move->getStartField();
	Field end = move->getEndField();
	std::stringstream ss;
	ss << "M" << start.x << start.y << end.x << end.y;
	String s= String(ss.str());
	return s;
}

Move* OnlinePlayer::stringToMove(String msg)
{
	if (msg[0] == 'M') {
		int sx = msg[1] - '0';
		int sy = msg[2] - '0';
		int ex = msg[3] - '0';
		int ey = msg[4] - '0';
		return new Move(Field(sx, sy), Field(ex, ey));
	}
	else {
		std::cerr << "Invalid move message: " << msg.toAnsiString() << std::endl;
		return nullptr;
	}
}
