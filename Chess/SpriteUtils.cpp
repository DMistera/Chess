#include "SpriteUtils.h"



SpriteUtils::SpriteUtils()
{
}


SpriteUtils::~SpriteUtils()
{
}

void SpriteUtils::centerOrigin(Sprite * sprite)
{
	FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void SpriteUtils::centerOrigin(Text * text)
{
	FloatRect bounds = text->getLocalBounds();
	text->setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}
