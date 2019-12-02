#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class AppConsts
{
public:
	static RenderWindow RENDER_WINDOW;
	static unsigned int getScreenWidth();
	static unsigned int getScreenHeight();
private:
	AppConsts();
};

