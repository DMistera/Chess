#include "Piece.h"
#include "GameState.h"


Piece::Piece(Side side, Field field) {
	m_side = side;
	m_field = field;
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

void Piece::searchLine(std::list<Field>& list, GameState& state, int xf, int yf)
{
	for (int i = 1; i < 8; i++) {
		Field f = Field(m_field.x + xf*i, m_field.y + yf*i);
		if (f.inBounds()) {
			if (!state.occupied(f)) {
				list.push_back(f);
			}
			else {
				if (state.getPieceAtField(f)->getSide() != m_side) {
					list.push_back(f);
				}
				break;
			}
		}
		else {
			break;
		}
	};
}
