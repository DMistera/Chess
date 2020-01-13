#pragma once
#include "Game.h"
class LocalGame :
	public Game
{
	// Inherited via Game
	virtual Player * createWhitePlayer() override;
	virtual Player * createBlackPlayer() override;
	virtual String whitePlayerMessage() override;
	virtual String blackPlayerMessage() override;
	virtual void afterPlayerTurn(Side side) override;
};

