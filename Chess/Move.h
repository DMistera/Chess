#pragma once

#include "Piece.h"
#include "Field.h"
#include <list>
#include <sstream>

class Move {
public:
	Move(Field startField, Field endField);
	Move(String str);
	~Move();
	String toString();
	Field getStartField();
	Field getEndField();
private:
	Field m_startField;
	Field m_endField;
};

