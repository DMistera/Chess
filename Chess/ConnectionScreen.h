#pragma once

#include "Frame.h"
#include "AppConsts.h"
#include "SpriteUtils.h"
#include "ServerConnection.h"
#include <thread>
#include <functional>
#include "FontManager.h"

class ConnectionScreen :
	public Frame
{
public:
	ConnectionScreen(ServerConnection* serverConnection);
	~ConnectionScreen();
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	virtual void update(float deltaTime) override;
	void onSuccess(std::function<void()> f);
private:
	std::function<void()> m_onSuccess;
	std::thread* m_connectThread;
	Text m_text;
	ServerConnection* m_connection;
	void tryConnect();
};

