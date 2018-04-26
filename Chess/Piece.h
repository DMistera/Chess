#pragma once

#include <string>
#include "Field.h"
#include <list>
#include "SFML\Graphics.hpp"
#include "Side.h"

using namespace sf;

class Piece {
public:
	Piece(Side side);
	~Piece();
	Sprite* getSprite();
	virtual std::string getImage() = 0;
	virtual std::list<Field> getAvailableFields(std::list<Piece*>* pieces) = 0;
	void initializeSprite();
	void setField(Field field);
	Side getSide();
	Field getField();
	static const unsigned int PIECE_SIZE = 50;
protected:
	Sprite * m_sprite;
	Side m_side;
	Field m_field;
	Piece* getPieceAtField(std::list<Piece*>* pieces, Field field);
	bool occupied(std::list<Piece*>* pieces, Field field);
};

