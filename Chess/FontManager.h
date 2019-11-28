#pragma once

#include "SFML/Graphics.hpp"
#include <map>
#include <iostream>

using namespace sf;

class FontManager
{
public:
	static Font* getFont(String fontName);
	static Font* getDefaultFont();
private:
	static std::map<String, Font*> m_fontMap;
	FontManager();
	~FontManager();
};

