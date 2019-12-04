#include "OnlineGame.h"


OnlineGame::OnlineGame(ServerConnection * serverConnection , Side localSide)
{
	m_connection = serverConnection;
	m_localSide = localSide;
	if (m_localSide == Side::BLACK) {
		m_reversed = true;
	}
}

OnlineGame::~OnlineGame()
{
}

Player * OnlineGame::createWhitePlayer()
{
	if (m_localSide == Side::WHITE) {
		return new HumanPlayer(Side::WHITE, m_reversed);
	}
	else {
		return new OnlinePlayer(Side::WHITE, m_connection, onlinePlayerErrorCallback());
	}
}

Player * OnlineGame::createBlackPlayer()
{
	if (m_localSide == Side::BLACK) {
		return new HumanPlayer(Side::BLACK, m_reversed);
	}
	else {
		return new OnlinePlayer(Side::BLACK, m_connection, onlinePlayerErrorCallback());
	}
}

std::function<void(String)> OnlineGame::onlinePlayerErrorCallback()
{
	return [&](String s) {
		showError(s);
	};
}

String OnlineGame::whitePlayerMessage()
{
	if (m_localSide == Side::WHITE) {
		return "Your turn!";
	}
	else {
		return "Waiting for\n opponent...";
	}
}

String OnlineGame::blackPlayerMessage()
{
	if (m_localSide == Side::BLACK) {
		return "Your turn!";
	}
	else {
		return "Waiting for\n opponent...";
	}
}
