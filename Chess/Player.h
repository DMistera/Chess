#pragma once

#include "Piece.h"
#include <list>
#include "Side.h"
#include "Move.h"
#include "GameState.h"

class Player {
public:
	virtual Move* requestMove(GameState* state) = 0;
	Player(Side white);
	~Player();
protected:
	Side m_side;
};

