#include "Rook.h"
#include "GameState.h"


Rook::Rook(Side side, int x) : Piece(side, side == Side::WHITE ? Field(x, 0) : Field(x, 7))
{
}


Rook::~Rook()
{
}

std::string Rook::getImage()
{
	return m_side == Side::WHITE ? "assets/whiteRook.png" : "assets/blackRook.png";
}

std::list<Field> Rook::getAvailableFields(GameState& state)
{
	std::list<Field> result;
	searchLine(result, state, 1, 0);
	searchLine(result, state, -1, 0);
	searchLine(result, state, 0, 1);
	searchLine(result, state, 0, -1);
	return result;
}
