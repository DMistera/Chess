#pragma once


#include "Frame.h"
#include "FontManager.h"
#include "SpriteUtils.h"

using namespace sf;

class TextField :
	public Frame
{
public:
	TextField(Vector2f position, String defaultValue);
	~TextField();

	// Inherited via Frame
	virtual void handleEvent(Event event) override;
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;

	String getValue();

private:
	String m_textStr;
	Text m_text;
	RectangleShape m_background;
};

