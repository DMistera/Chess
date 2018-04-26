#include "Pawn.h"

Pawn::Pawn(Side side) : Piece(side) {
}

Pawn::~Pawn() {
}

std::string Pawn::getImage() {
	return m_side == Side::WHITE ? "assets/whitePawn.png" : "assets/blackPawn.png";
}

std::list<Field> Pawn::getAvailableFields(std::list<Piece*>* pieces) {
	std::list<Field> fields;
	Field forward1;
	bool f1 = false;
	Field forward2;
	bool f2 = false;
	if (m_side == Side::WHITE) {
		if (m_field.y < 7) {
			forward1 = Field(m_field.x, m_field.y + 1);
			f1 = true;
		}
		if (m_field.y == 1) {
			forward2 = Field(m_field.x, m_field.y + 2);
			f2 = true;
		}
	}
	else {
		if (m_field.y > 0) {
			forward1 = Field(m_field.x, m_field.y - 1);
			f1 = true;
		}
		if (m_field.y == 6) {
			forward2 = Field(m_field.x, m_field.y - 2);
			f2 = true;
		}
	}
	if (f1 && !occupied(pieces, forward1)) {
		fields.push_back(forward1);
	}
	if (f2 && !occupied(pieces, forward1) && !occupied(pieces, forward2)) {
		fields.push_back(forward2);
	}
	return fields;
}
