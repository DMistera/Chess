#pragma once

#include "TextField.h"
#include "Button.h"
#include <functional>
#include "BackgroundScreen.h"

using namespace sf;

class ServerInputScreen : public BackgroundScreen
{
public:
	ServerInputScreen();
	~ServerInputScreen();
	void onAccept(std::function<void(String)> f);
	// Inherited via Frame
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;

private:
	Text m_label;
	TextField m_textField;
	Button m_acceptButton;
	std::function<void(String)> m_onAccept;
};

