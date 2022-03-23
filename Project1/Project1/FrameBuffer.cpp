#include "FrameBuffer.h"
#include <iostream>


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
		v.location	= glm::vec4{data[i], data[i + 1], data[i + 2], 1.0f};
		v.color		= glm::vec3{data[i + 3], data[i + 4], data[i + 5]};
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


//void FrameBuffer::loadMesh(Mesh m, glm::vec3 position)
//{
//	ThisMeshes[m] = position;
//}
//
//void FrameBuffer::delMesh(Mesh m)
//{
//	ThisMeshes.erase(m);
//}

void FrameBuffer::draw(int mode)
{
	this->clearColor(glm::vec3{ 0.0f, 0.0f, 0.0f });
	cv::Mat image(800, 800, CV_32FC3, this->frame_buffer().data());
	if (mode == 0)
	{
		std::vector<Triangle>::iterator t;
		for (t = Thistriangles.begin(); t != Thistriangles.end(); t++)
		{
			cv::Point p1(shader->vertexShader(t->a()).windowPos.x, shader->vertexShader(t->a()).windowPos.y);
			cv::Point p2(shader->vertexShader(t->b()).windowPos.x, shader->vertexShader(t->b()).windowPos.y);
			cv::Point p3(shader->vertexShader(t->c()).windowPos.x, shader->vertexShader(t->c()).windowPos.y);
			cv::line(image, p1, p2, cv::Scalar(255, 255, 255), 1, 1);
			cv::line(image, p2, p3, cv::Scalar(255, 255, 255), 1, 1);
			cv::line(image, p3, p1, cv::Scalar(255, 255, 255), 1, 1);
		}
	}
	else if (mode == 1)
	{
		std::vector<Triangle>::iterator t;
		for (t = Thistriangles.begin(); t != Thistriangles.end(); t++)
		{
			Vout v1 = shader->vertexShader(t->a());
			Vout v2 = shader->vertexShader(t->b());
			Vout v3 = shader->vertexShader(t->c());
			drawTriangle(v1, v2, v3);
		}
	}
	imshow("soft render", image);
}

void FrameBuffer::drawTriangle(const Vout &v1, const Vout &v2, const Vout &v3)
{
	Vout tem[3] = {v1, v2, v3}; // 按照从上到下的顺序排序v1, v2, v3
	Vout temp;
	if (tem[0].windowPos.y > tem[1].windowPos.y)
	{
		temp = tem[0];
		tem[0] = tem[1];
		tem[1] = temp;
	}
	if (tem[1].windowPos.y > tem[2].windowPos.y)
	{
		temp = tem[1];
		tem[1] = tem[2];
		tem[2] = temp;
	}
	if (tem[0].windowPos.y > tem[1].windowPos.y)
	{
		temp = tem[0];
		tem[0] = tem[1];
		tem[1] = temp;
	}

	if (tem[0].windowPos.y == tem[1].windowPos.y)
		drawDownTriangle(tem[0], tem[1], tem[2]);
	else if (tem[1].windowPos.y == tem[2].windowPos.y)
		drawUpTriangle(tem[0], tem[1], tem[2]);
	else
	{
		float w = (tem[1].windowPos.y - tem[0].windowPos.y) / (tem[2].windowPos.y - tem[1].windowPos.y);
		Vout vmid = Vout::lerp(tem[0], tem[2], w);
		drawUpTriangle(tem[0], tem[1], vmid);
		drawDownTriangle(tem[1], vmid, tem[2]);
	}

}

void FrameBuffer::drawUpTriangle(const Vout &v1, const Vout &v2, const Vout &v3)
{
	Vout top, left, right, temLeft, temRight;
	top = v1;
	left = v2.windowPos.x < v3.windowPos.x ? v2:v3;
	right = v2.windowPos.x > v3.windowPos.x ? v2:v3;

	for (int i = top.windowPos.y; i <= left.windowPos.y; i++)
	{
		float w = (i - top.windowPos.y) / (left.windowPos.y - top.windowPos.y);
		temLeft = Vout::lerp(top, left, w);
		temRight = Vout::lerp(top, right, w);
		temLeft.windowPos.y = i;
		temRight.windowPos.y = i;
		scanLine(temLeft, temRight);
	}
}

void FrameBuffer::drawDownTriangle(const Vout &v1, const Vout &v2, const Vout &v3)
{
	Vout down, left, right, temLeft, temRight;
	down = v3;
	left = v2.windowPos.x < v1.windowPos.x ? v2 : v1;
	right = v2.windowPos.x > v1.windowPos.x ? v2 : v1;

	for (int i = down.windowPos.y; i >= left.windowPos.y; i--)
	{
		float w = (i - down.windowPos.y) / (left.windowPos.y - down.windowPos.y);
		temLeft = Vout::lerp(down, left, w);
		temRight = Vout::lerp(down, right, w);
		temLeft.windowPos.y = i;
		temRight.windowPos.y = i;
		scanLine(temLeft, temRight);
	}
}

void FrameBuffer::scanLine(const Vout &v1, const Vout &v2)
{
	float total = v2.windowPos.x - v1.windowPos.x;
	for (int i = v1.windowPos.x; i <= v2.windowPos.x; i++)
	{
		Vout v = Vout::lerp(v1, v2, (i - v1.windowPos.x) / total);
		setPoint(i, v1.windowPos.y, shader->FragmentShader(v));
	}
}
