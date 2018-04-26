#pragma once

#include "Piece.h"
#include "Field.h"
#include <list>

class Move {
public:
	Move(Piece* piece, Field field);
	~Move();
	void execute(std::list<Piece*>* pieces);
private:
	Piece * m_piece;
	Field m_field;
};

