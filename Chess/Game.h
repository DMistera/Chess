#pragma once

#include "Pawn.h"
#include "King.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "HumanPlayer.h"
#include "Side.h"
#include "Animation.h"
#include <list>
#include <thread>
#include "GameState.h"
#include "Frame.h"

using namespace sf;

class Game : public Frame {
public:
	Game(RenderWindow* renderwindow);
	void update(float deltaTime) override;
	void draw() override;
private:
	void turnLoop();
	Player* getActivePlayer();
	bool checkmate();
	bool m_animationState;
	Player* m_black;
	Player* m_white;
	GameState* m_state;
	Animation* m_animation;
	std::thread* m_turnsThread;
};

