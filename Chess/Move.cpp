#include "Move.h"




Move::Move(Piece * piece, Field field) {
	m_piece = piece;
	m_field = field;
}

Move::~Move() {
}

Piece * Move::getPiece() {
	return m_piece;
}

Field Move::getField()
{
	return m_field;
}
