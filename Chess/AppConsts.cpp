#include "AppConsts.h"

RenderWindow AppConsts::RENDER_WINDOW(VideoMode(400, 500), "Chess");

unsigned int AppConsts::getScreenWidth()
{
	return RENDER_WINDOW.getSize().x;
}

unsigned int AppConsts::getScreenHeight()
{
	return RENDER_WINDOW.getSize().y;
}

AppConsts::AppConsts()
{
}
