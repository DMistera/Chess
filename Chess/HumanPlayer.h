#pragma once

#include "Player.h"
#include "Side.h"
#include "FieldUtils.h"
#include "SFML\Window.hpp"
#include <list>

#include "AppConsts.h"

class HumanPlayer : public Player, public Drawable {
public:

	HumanPlayer(Side side, bool reversed);
	~HumanPlayer();
	virtual Move* requestMove(GameState* state) override;
	virtual void draw(RenderTarget & target, RenderStates states) const override;
private:
	Piece * m_selectedPiece;
	bool m_clicked;
	bool m_reversed;
	std::list<Field> m_availableMoves;

	//Drawable
	CircleShape* m_selectedPieceShape;
	std::list<Shape*> m_availableMovesShapes;
};

