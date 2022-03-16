#include "Triangle.h"

Triangle::Triangle(glm::vec4* pos, glm::vec3* color, glm::vec3* normal, glm::vec2* texcoord)
{
	for (int i = 0; i < 3; i++)
	{
		this->setPos(i, pos[i]);
		this->setColor(i, color[i]);
		this->setNormal(i, normal[i]);
		this->setTexCoord(i, texcoord[i]);
	}
}

Triangle::Triangle(glm::vec4* pos, glm::vec3* color)
{
	for (int i = 0; i < 3; i++)
	{
		this->setPos(i, pos[i]);
		this->setColor(i, color[i]);
	}
}

void Triangle::setPos(int i, glm::vec4 vertex)
{
	this->vertices[i].position = vertex;
}

void Triangle::setColor(int i, glm::vec3 color)
{
	this->vertices[i].color = color;
}

void Triangle::setNormal(int i, glm::vec3 normal)
{
	this->vertices[i].normal = normal;
}

void Triangle::setTexCoord(int i, glm::vec2 texcoord)
{
	this->vertices[i].Texcoord = texcoord;
}
