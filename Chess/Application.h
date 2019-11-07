#pragma once

#include "Frame.h"
#include "Menu.h"
#include "Game.h"

class Application : public Frame
{
public:
	Application(RenderWindow * renderwindow);
	~Application();
	virtual void update(float deltaTime) override;
	virtual void draw() override;
private:
	Game* m_game;
	Menu* m_menu;
	Frame* m_activeFrame;
};

