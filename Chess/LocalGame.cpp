#include "LocalGame.h"

Player * LocalGame::createWhitePlayer()
{
	return new HumanPlayer(Side::WHITE, false);
}

Player * LocalGame::createBlackPlayer()
{
	return new HumanPlayer(Side::BLACK, true);
}

String LocalGame::whitePlayerMessage()
{
	return "White player's turn!";
}

String LocalGame::blackPlayerMessage()
{
	return "Black player's turn!";
}

void LocalGame::afterPlayerTurn(Side side)
{
	if (side == Side::WHITE) {
		m_reversed = true;
	}
	else {
		m_reversed = false;
	}
}
