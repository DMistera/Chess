#include "Piece.h"


Piece::Piece(Side side) {
	m_side = side;
}

Piece::~Piece() {
}

Sprite * Piece::getSprite() {
	return m_sprite;
}

void Piece::initializeSprite() {
	m_sprite = new Sprite();
	Texture* texture = new Texture();
	std::string image = getImage();
	texture->loadFromFile(image);
	m_sprite->setTexture(*texture);
}

void Piece::setField(Field field) {
	m_field = field;
}

Side Piece::getSide() {
	return m_side;
}

Field Piece::getField() {
	return m_field;
}

Piece * Piece::getPieceAtField(std::list<Piece*>* pieces, Field field) {
	for (std::list<Piece*>::iterator it = pieces->begin(); it != pieces->end(); ++it) {
		Piece* piece = (*it);
		if (piece->getField().x == field.x && piece->getField().y == field.y) {
			return piece;
		}
	}
	return 0;
}

bool Piece::occupied(std::list<Piece*>* pieces, Field field) {
	return getPieceAtField(pieces, field) != 0;
}
