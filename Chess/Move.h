#pragma once

#include "Piece.h"
#include "Field.h"
#include <list>

class Move {
public:
	Move(Field startField, Field endField);
	~Move();
	Field getStartField();
	Field getEndField();
private:
	Field m_startField;
	Field m_endField;
};

