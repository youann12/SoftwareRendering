#include "FrameBuffer.h"
#include <iostream>

FrameBuffer::FrameBuffer( int w = 800,  int h = 800)
{
	this->width = w;
	this->height = h;
	this->framebuffer.resize((double)this->width * (double)this->height);
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

void FrameBuffer::loadData(float data[], int ind[], int numVertices, int numTriangles)
{

	std::vector<vertexData> vertices;
	
	for (int i = 0; i < numVertices; i += 6)
	{
		vertexData v;
		std::cout << data[i] << data[i + 1] << data[i + 2] << std::endl;
		v.location	= glm::vec4{data[i], data[i + 1], data[i + 2], 1.0f};
		v.color		= glm::vec3{ data[i + 3], data[i + 4], data[i + 5]};
		vertices.push_back(v);
	}

	
	for (int i = 0; i <= numTriangles; i += 3)
	{
		glm::vec4 tVertices[3]	= { vertices[i].location, vertices[i + 1].location, vertices[i + 2].location };
		glm::vec3 tColors[3]	= { vertices[i].color, vertices[i + 1].color, vertices[i + 2].color };
		Triangle t = Triangle(tVertices, tColors);
		this->Thistriangles.push_back(t);
	}
}

void FrameBuffer::loadData(vertexData* data)
{
}
