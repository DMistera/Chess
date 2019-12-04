#pragma once

#include <string>
#include "Field.h"
#include <list>
#include "SFML\Graphics.hpp"
#include "Side.h"
#include <iostream>

using namespace sf;

class GameState;

class Piece {
public:
	enum Type {
		PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
	};

	Piece(Side side, Field field);
	~Piece();
	Sprite* getSprite();
	virtual std::string getImage() = 0;
	virtual Type getType() = 0;
	virtual std::list<Field> getAvailableFields(GameState& state) = 0;
	void initializeSprite();
	void setField(Field field);
	Side getSide();
	Field getField();
	static const unsigned int PIECE_SIZE = 50;
protected:
	void searchLine(std::list<Field>& list, GameState& state, int xf, int yf);
	Sprite * m_sprite;
	Side m_side;
	Field m_field;
};

