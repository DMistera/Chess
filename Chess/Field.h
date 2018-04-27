#pragma once

#include "SFML\System.hpp"

using namespace sf;

class Piece;


class Field {
public:
	Field(int x, int y);
	Field();
	~Field();
	int x;
	int y;
};

