#include "FontManager.h"

std::map<String, Font*> FontManager::m_fontMap;

Font* FontManager::getFont(String fontName)
{
	std::map<String, Font*>::iterator it = m_fontMap.find(fontName);
	if (it != m_fontMap.end()) {
		return it->second;
	}
	else {
		Font* font = new Font();
		if (!font->loadFromFile(fontName)) {
			std::cerr << "Failed to load font " << (std::string)fontName << std::endl;
		}
		m_fontMap.insert(std::pair<String, Font*>(fontName, font));
		return font;
	}
}

Font * FontManager::getDefaultFont()
{
	return getFont("assets/McLaren-Regular.ttf");
}

FontManager::FontManager()
{
}


FontManager::~FontManager()
{
}
