#ifndef TRIANGLE_H
#define TRIANGLE_H

#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct vertex
{
	glm::vec4 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 Texcoord;
};


class Triangle
{
public:
	Triangle(glm::vec4* vertex, glm::vec3* color, glm::vec3 *normal, glm::vec2 *texcoord);
	Triangle(glm::vec4* vertex, glm::vec3* color);
	Triangle(glm::vec4* vertex, glm::vec3* color, glm::vec2* texcoord);
	~Triangle() = default;

	vertex vertices[3];

	vertex a() const { return vertices[0]; };
	vertex b() const { return vertices[1]; };
	vertex c() const { return vertices[2]; };

	void setPos			(int i, glm::vec4 vertex);
	void setColor		(int i, glm::vec3 color);
	void setNormal		(int i, glm::vec3 normal);
	void setTexCoord	(int i, glm::vec2 texcoord);

};
#endif // !TRIANGLE_H
