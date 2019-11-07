#pragma once

#include "Frame.h"
#include "Button.h"

class Menu : public Frame
{
public:
	Menu(RenderWindow*);
	~Menu();
	virtual void update(float deltaTime) override;
	virtual void draw() override;
private:
	Button* m_playOnlineButton;
};

