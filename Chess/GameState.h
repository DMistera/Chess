#pragma once

#include <list>
#include "Piece.h"
#include "Move.h"
#include "Pawn.h"
#include "King.h"

class GameState
{
public:
	GameState();
	~GameState();
	void applyMove(Move* move);
	std::list<Piece*> getPieces();
	Piece* getPieceAtField( Field field);
	bool occupied(Field field);
	Side getActiveSide();
	void setActiveSide(Side side);
private:
	std::list<Piece*> m_pieces;
	Side m_activeSide;
};

