#pragma once
#include "Frame.h"
#include "FontManager.h"
#include <functional>
#include "AppConsts.h"
#include "SpriteUtils.h"

using namespace sf;

class Button :
	public Frame
{
public:
	Button(Vector2f scale, Vector2f pos, String label);
	~Button();
	void setCallback(std::function<void()> callback);
	virtual void update(float deltaTime) override;
	virtual void drawFrame(RenderTarget & target, RenderStates states) const override;
private:
	bool pointInside(Vector2i p);
	Vector2f m_position;
	Vector2f m_scale;
	Text m_text;
	RectangleShape m_rect;
	std::function<void()> m_callback;
	bool m_clicked;
	static Texture* m_texture;
};

