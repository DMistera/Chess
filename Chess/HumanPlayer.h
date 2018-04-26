#pragma once

#include "Player.h"
#include "Side.h"
#include "SFML\Window.hpp"
#include <list>

class HumanPlayer : public Player {
public:

	HumanPlayer(Side side, RenderWindow* renderWindow);
	~HumanPlayer();

	// Inherited via Player
	virtual bool move(std::list<Piece*>* pieces) override;
	void draw();

private:
	Field coordToField(Vector2i coords);
	Vector2f fieldToCoord(Field field);
	Piece * m_selectedPiece;
	RenderWindow* m_renderWindow;
	bool m_clicked;
	std::list<Field> m_availableMoves;

	//Drawable
	CircleShape* m_selectedPieceShape;
	std::list<CircleShape*> m_availableMovesShapes;
};

