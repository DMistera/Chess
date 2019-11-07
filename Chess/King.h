#pragma once
#include "Piece.h"
#include <list>

class King :
	public Piece {
public:
	King(Side);
	~King();

	// Inherited via Piece
	virtual std::string getImage() override;
	virtual std::list<Field> getAvailableFields(GameState* state) override;
};

