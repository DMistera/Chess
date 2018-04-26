#pragma once

#include "Piece.h"
#include <list>
#include "Side.h"

class Player {
public:
	virtual bool move(std::list<Piece*>* pieces) = 0;
	Player(Side white);
	~Player();
protected:
	Side m_side;
	void makeMove(Piece* piece, Field field);
};

