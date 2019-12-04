#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight(Side side, int x);
	~Knight();

	// Inherited via Piece
	virtual std::string getImage() override;
	virtual std::list<Field> getAvailableFields(GameState & state) override;
};

