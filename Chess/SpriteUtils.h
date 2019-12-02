#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class SpriteUtils
{
public:
	SpriteUtils();
	~SpriteUtils();
	static void centerOrigin(Sprite* sprite);
	static void centerOrigin(Text* text);
};

