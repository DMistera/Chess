#pragma once

#include "Frame.h"
#include "Button.h"
#include <functional>
#include "ServerConnection.h"
#include "FontManager.h"

class Menu : public Frame
{
public:
	Menu();
	~Menu();
	void onPlayOnline(std::function<void()> f);
	virtual void update(float deltaTime) override;
	virtual void draw(RenderTarget & target, RenderStates states) const override;
private:
	Button* m_playOnlineButton;
	std::function<void()> m_onPlayOnline;
};

