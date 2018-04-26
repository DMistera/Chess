#pragma once

#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(Side side);
	~Pawn();

	// Inherited via Piece
	virtual std::string getImage() override;
	virtual std::list<Field> getAvailableFields(std::list<Piece*>* pieces) override;
};

