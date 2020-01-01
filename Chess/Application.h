#pragma once

#include "Frame.h"
#include "Menu.h"
#include "OnlineGame.h"
#include "ServerConnection.h"
#include "WaitingScreen.h"
#include "ConnectionScreen.h"
#include "ServerInputScreen.h"

class Application : public Frame
{
public:
	Application();
	~Application();
private:
	void setActiveFrame(Frame* frame);

	ServerInputScreen* m_serverInputScreen;
	ConnectionScreen* m_connectionScreen;
	Menu* m_menu;
	WaitingScreen* m_waitingScreen;
	Game* m_game;
	ServerConnection* m_serverConnection;

	Frame* m_activeFrame;
	// Inherited via Frame
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
};

