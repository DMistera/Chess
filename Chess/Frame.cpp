#include "Frame.h"



Frame::Frame()
{
}


Frame::~Frame()
{
}

void Frame::draw(RenderTarget & target, RenderStates states) const
{
	// Draw optimization may be possible?
	drawFrame(target, states);
}
