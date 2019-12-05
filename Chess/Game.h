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
#include "Button.h"
#include "SpriteUtils.h"

using namespace sf;

class Game : public Frame {
public:
	Game();
	void update(float deltaTime) override;
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
	void initPlayers();
	void onExit(std::function<void()>);
protected:
	void showError(String message);
	void showMessage(String message);
	bool m_reversed;
	virtual Player* createWhitePlayer() = 0;
	virtual Player* createBlackPlayer() = 0;
	virtual String whitePlayerMessage() = 0;
	virtual String blackPlayerMessage() = 0;
	virtual void afterPlayerTurn(Side side) = 0;
	void turnLoop();
	Player* getActivePlayer() const;
	bool checkmate(Side side);
	bool m_animationState;
	bool m_exitable;
	Player* m_black;
	Player* m_white;
	Text m_text;
	String m_textString;
	Color m_textColor;
	Button* m_exitButton;
	GameState m_state;
	Animation* m_animation;
	std::thread* m_turnsThread;
	std::list<RectangleShape> m_chessBoard;
	std::function<void()> m_onExit;
};

