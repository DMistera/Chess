#pragma once

#include "Frame.h"
#include "Menu.h"
#include "OnlineGame.h"
#include "ServerConnection.h"
#include "WaitingScreen.h"
#include "ConnectionScreen.h"

class Application : public Frame
{
public:
	Application();
	~Application();
	virtual void update(float deltaTime) override;
private:
	void setActiveFrame(Frame* frame);
	Frame* m_activeFrame;
	ServerConnection* m_serverConnection;
	// Inherited via Frame
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
};

