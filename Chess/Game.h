#pragma once

#include "Pawn.h"
#include "King.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "HumanPlayer.h"
#include "Side.h"
#include "Animation.h"
#include <list>

using namespace sf;

class Game {
public:
	Game(RenderWindow* renderwindow);
	void update(double deltaTime);
	void draw();
private:
	bool checkmate();
	bool m_animationState;
	RenderWindow* m_renderWindow;
	Player* m_black;
	Player* m_white;
	std::list<Piece*> m_pieces;
	Player* m_currentPlayer;
	Animation* m_animation;
};

