#include "FrameBuffer.h"
#include <iostream>

FrameBuffer::FrameBuffer( int w = 800,  int h = 800)
{
	this->width = w;
	this->height = h;
	this->framebuffer.resize((double)this->width * (double)this->height);
	this->clearColor(glm::vec3{ 0.0f, 0.0f, 0.0f });
}

FrameBuffer::FrameBuffer()
{
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
	// load vertex data, include vertices attributes
	for (int i = 0; i < numVertices; i += 6)
	{
		vertexData v;
		std::cout << data[i] << data[i + 1] << data[i + 2] << std::endl;
		v.location	= glm::vec4{data[i], data[i + 1], data[i + 2], 1.0f};
		v.color		= glm::vec3{ data[i + 3], data[i + 4], data[i + 5]};
		vertices.push_back(v);
	}

	// according to index array and vertices array to construct triangle
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

void FrameBuffer::draw(int mode)
{
	this->clearColor(glm::vec3{ 0.0f, 0.0f, 0.0f });
	cv::Mat image(800, 800, CV_32FC3, this->frame_buffer().data());
	if (mode == 0)
	{
		std::vector<Triangle>::iterator t;
		for (t = Thistriangles.begin(); t != Thistriangles.end(); t++)
		{
			cv::Point p1(t->a().x, t->a().y);
			cv::Point p2(t->b().x, t->b().y);
			cv::Point p3(t->c().x, t->c().y);
			cv::line(image, p1, p2, cv::Scalar(255, 255, 255), 1, 4);
			cv::line(image, p2, p3, cv::Scalar(255, 255, 255), 1, 4);
			cv::line(image, p3, p1, cv::Scalar(255, 255, 255), 1, 4);
		}
	}
	imshow("soft render", image);
}
