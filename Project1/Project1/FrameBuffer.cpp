#include "FrameBuffer.h"


FrameBuffer::FrameBuffer( int w = 800,  int h = 800)
{
	this->width = w;
	this->height = h;
	this->framebuffer.resize(this->width * this->height);
	this->clearColor(glm::vec3{ 0.0f, 1.0f, 0.0f });
}

void FrameBuffer::setPoint(int x, int y, glm::vec3 color)
{
	if (x < 0 || x >= this->width || y < 0 || y >= this->height)
		return;
	int ind = this->width * y + x;
	this->framebuffer[ind] = color;
}

void FrameBuffer::setLine(glm::vec2 start, glm::vec2 end, glm::vec3 color)
{
}

void FrameBuffer::clearColor(glm::vec3 color)
{
	std::fill(framebuffer.begin(), framebuffer.end(), color);
}
