#include "Move.h"




Move::Move(Field startField, Field endField) {
	m_startField = startField;
	m_endField = endField;
}

Move::~Move() {
}

Field Move::getStartField()
{
	return m_startField;
}

Field Move::getEndField()
{
	return m_endField;
}
