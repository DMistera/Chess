#pragma once

#include "Frame.h"
#include "Menu.h"
#include "Game.h"
#include "ServerConnection.h"

class Application : public Frame
{
public:
	Application();
	~Application();
	virtual void update(float deltaTime) override;
private:
	Game* m_game;
	Menu* m_menu;
	Frame* m_activeFrame;
	ServerConnection* m_serverConnection;
	// Inherited via Frame
	virtual void draw(RenderTarget & target, RenderStates states) const override;
};

