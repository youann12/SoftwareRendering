#include "Triangle.h"

Triangle::Triangle(glm::vec4* vertex, glm::vec3* color, glm::vec3* normal, glm::vec2* texcoord)
{
	for (int i = 0; i < 3; i++)
	{
		this->setVertex(i, vertex[i]);
		this->setColor(i, color[i]);
		this->setNormal(i, normal[i]);
		this->setTexCoord(i, texcoord[i]);
	}
}

void Triangle::setVertex(int i, glm::vec4 vertex)
{
	this->vertices[i] = vertex;
}

void Triangle::setColor(int i, glm::vec3 color)
{
	this->color[i] = color;
}

void Triangle::setNormal(int i, glm::vec3 normal)
{
	this->normal[i] = normal;
}

void Triangle::setTexCoord(int i, glm::vec2 texcoord)
{
	this->TexCoord[i] = texcoord;
}
