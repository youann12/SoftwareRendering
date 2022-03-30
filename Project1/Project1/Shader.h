#pragma once
#include "Triangle.h"
#include "Vout.h"

class Shader
{
public:
	Shader() {}
	~Shader() = default;
	void setModel(glm::vec3 pos, glm::vec3 scale, float angle, glm::vec3 axis);
	void setViewPort(int x, int y, int width, int height);
	void setView(glm::vec3 pos, glm::vec3 front, glm::vec3 right, glm::vec3 up);
	void setProjection(float eye_fov, float aspect_ratio, float zNear, float zFar);
	Vout vertexShader(vertex v);
	glm::vec3 FragmentShader(Vout v);


private:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 viewport;
};
