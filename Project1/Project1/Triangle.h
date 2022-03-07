#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Triangle
{
	Triangle(glm::vec4* vertex, glm::vec3* color, glm::vec3 *normal, glm::vec2 *texcoord);
	~Triangle() = default;
public:
	glm::vec4 vertices[3];
	glm::vec3 color[3];
	glm::vec3 normal[3];
	glm::vec2 TexCoord[3];

	glm::vec4 a() const { return vertices[0]; };
	glm::vec4 b() const { return vertices[1]; };
	glm::vec4 c() const { return vertices[2]; };

private:
	void setVertex	 (int i, glm::vec4 vertex);
	void setColor	 (int i, glm::vec3 color);
	void setNormal	 (int i, glm::vec3 normal);
	void setTexCoord (int i, glm::vec2 texcoord);

};