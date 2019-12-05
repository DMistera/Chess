#pragma once

#include "Frame.h"
#include "Button.h"
#include "ServerConnection.h"
#include <functional>
#include "SpriteUtils.h"
#include "Side.h"

class WaitingScreen :
	public Frame
{
public:
	WaitingScreen(ServerConnection*);
	~WaitingScreen();
	void onOpponentFound(std::function<void(Side localSide)>);
	void onCancel(std::function<void()>);
private:
	std::function<void(Side localSide)> m_onOpponentFound;
	std::function<void()> m_onCancel;
	Text* m_waitingForOpponentText;
	Button* m_cancelButton;

	// Inherited via Frame
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
	virtual void update(float deltaTime) override;
};

