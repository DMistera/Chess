#include "Frame.h"



Frame::Frame()
{
}


Frame::~Frame()
{
}

void Frame::update(float deltaTime)
{
	for (auto frame : m_subframes) {
		frame->update(deltaTime);
	}
}

void Frame::handleEvent(Event event)
{
	for (auto frame : m_subframes) {
		frame->handleEvent(event);
	}
}

void Frame::draw(RenderTarget & target, RenderStates states) const
{
	// Draw optimization may be possible?
	drawFrame(target, states);
}
