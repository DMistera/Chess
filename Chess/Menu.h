#pragma once

#include "BackgroundScreen.h"
#include "Button.h"
#include <functional>
#include "ServerConnection.h"
#include "FontManager.h"

class Menu : public BackgroundScreen
{
public:
	Menu();
	~Menu();
	void onPlayOnline(std::function<void()> f);
	virtual void update(float deltaTime) override;
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
private:
	Button* m_playOnlineButton;
	std::function<void()> m_onPlayOnline;
};

