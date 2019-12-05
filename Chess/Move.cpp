#include "Move.h"




Move::Move(Field startField, Field endField) {
	m_startField = startField;
	m_endField = endField;
}

Move::Move(String msg)
{
	if (msg[0] == 'M') {
		int sx = msg[1] - '0';
		int sy = msg[2] - '0';
		int ex = msg[3] - '0';
		int ey = msg[4] - '0';
		m_startField = Field(sx, sy);
		m_endField = Field(ex, ey);
	}
	else {
		std::cerr << "Invalid move message: " << msg.toAnsiString() << std::endl;
		throw std::exception();
	}
}

Move::~Move() {
}

String Move::toString()
{
	std::stringstream ss;
	ss << "M" << m_startField.x << m_startField.y << m_endField.x << m_endField.y;
	String s = String(ss.str());
	return s;
}

Field Move::getStartField()
{
	return m_startField;
}

Field Move::getEndField()
{
	return m_endField;
}
