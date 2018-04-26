#include "Move.h"




Move::Move(Piece * piece, Field field) {
	m_piece = piece;
	m_field = field;
}

Move::~Move() {
}

void Move::execute(std::list<Piece*>* pieces) {
	Piece* p = Piece::getPieceAtField(*pieces, m_field);
	if (p != 0) {
		pieces->remove(p);
	}
	m_piece->setField(m_field);
}
