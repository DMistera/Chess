#include "Piece.h"
#include "GameState.h"


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
	if (!texture->loadFromFile(image)) {
		std::cout << "Failed to load " + image << std::endl;
	}
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
