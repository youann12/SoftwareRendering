#pragma once
#include "Triangle.h"
#include "Vout.h"

class Shader
{
public:
	Shader(){ }
	~Shader() = default;
	void setModel(glm::mat4 m);
	void setView(int x, int y, int width, int height);
	void setProjection(glm::mat4 p);
	Vout vertexShader(vertex v);
	glm::vec3 FragmentShader(Vout v);


private:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	
};