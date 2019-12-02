#include "GameState.h"



GameState::GameState()
{
	m_pieces = std::list<Piece*>();

	//Set up a starting board
	//Pawns
	for (int i = 0; i < 8; i++) {
		Pawn* whitePawn = new Pawn(Side::WHITE);
		whitePawn->initializeSprite();
		whitePawn->setField(Field(i, 1));
		m_pieces.push_back(whitePawn);

		Pawn* blackPawn = new Pawn(Side::BLACK);
		blackPawn->initializeSprite();
		blackPawn->setField(Field(i, 6));
		m_pieces.push_back(blackPawn);
	}

	//Kings
	for (int i = 0; i < 2; i++) {
		int y = i == 0 ? 0 : 7;
		Side side = i == 0 ? Side::WHITE : Side::BLACK;
		King* king = new King(side);
		king->initializeSprite();
		king->setField(Field(4, y));
		m_pieces.push_back(king);
	}
}


GameState::~GameState()
{
}

void GameState::applyMove(Move* move)
{
	if (move) {
		Piece* target = getPieceAtField(move->getEndField());
		if (target) {
			m_pieces.remove(target);
		}
		Piece* p = getPieceAtField(move->getStartField());
		p->setField(move->getEndField());

		if (m_lastMove) {
			delete m_lastMove;
		}
		m_lastMove = move;
	}
	else {
		std::cerr << "Move was null" << std::endl;
	}
}

std::list<Piece*> GameState::getPieces()
{
	return m_pieces;
}

Piece * GameState::getPieceAtField(Field field)
{
	for (std::list<Piece*>::iterator it = m_pieces.begin(); it != m_pieces.end(); ++it) {
		Piece* piece = (*it);
		if (piece->getField().x == field.x && piece->getField().y == field.y) {
			return piece;
		}
	}
	return nullptr;
}

bool GameState::occupied(Field field)
{
	return getPieceAtField(field) != nullptr;
}

Side GameState::getActiveSide()
{
	return m_activeSide;
}

void GameState::setActiveSide(Side side)
{
	m_activeSide = side;
}

Move * GameState::getLastMove()
{
	return m_lastMove;
}
