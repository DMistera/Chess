#pragma once

#include <list>
#include "Piece.h"
#include "Move.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"

class GameState
{
public:
	GameState();
	~GameState();
	void applyMove(Move* move);
	std::list<Piece*> getPieces() const;
	Piece* getPieceAtField( Field field);
	King* getKing(Side side);
	bool occupied(Field field);
	Side getActiveSide() const;
	void setActiveSide(Side side);
	Move* getLastMove();
	bool checkMate(Side side);
private:
	Move* m_lastMove;
	std::list<Piece*> m_pieces;
	Side m_activeSide;
};

