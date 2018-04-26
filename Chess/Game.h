#pragma once

#include "Pawn.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "HumanPlayer.h"
#include "Side.h"
#include <list>

using namespace sf;

class Game {
public:
	Game(RenderWindow* renderwindow);
	void update();
	void draw();
private:
	bool checkmate();
	RenderWindow* m_renderWindow;
	Player* m_black;
	Player* m_white;
	std::list<Piece*>* m_pieces;
	Player* m_currentPlayer;
};

