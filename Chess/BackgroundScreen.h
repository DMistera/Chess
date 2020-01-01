#pragma once
#include "Frame.h"
#include "AppConsts.h"

class BackgroundScreen :
	public Frame
{
public:
	BackgroundScreen();

	// Inherited via Frame
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
private:
	RectangleShape m_background;
	static Texture* m_texture;
};

