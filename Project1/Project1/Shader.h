#pragma once
#include "Triangle.h"

class Shader
{
public:
	Shader(){ }
	~Shader() = default;
	void setModel(glm::mat4 m);
	void setView(glm::mat4 v);
	void setProjection(glm::mat4 p);
	glm::vec4 vertexShader(vertex v);
	


private:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	
};