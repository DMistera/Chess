#pragma once

#include "Piece.h"
#include <list>
#include "Side.h"
#include "Move.h"

class Player {
public:
	virtual Move* requestMove(std::list<Piece*> pieces) = 0;
	Player(Side white);
	~Player();
protected:
	Side m_side;
};

