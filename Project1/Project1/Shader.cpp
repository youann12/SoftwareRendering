#include "Shader.h"

void Shader::setModel(glm::mat4 m)
{
	model = m;
}

void Shader::setView(glm::mat4 v)
{
	view = v;
}

void Shader::setProjection(glm::mat4 p)
{
	projection = p;
}

void Shader::vertexTransform()
{
	glm::mat4x4 mvp = { 0.5,0,0,0,0,0.5,0,0,0,0,0.5,0,0,0,0,1 };//projection * view * model;
	Frame->framebuffer;
	std::vector<Triangle>::iterator t;
	for (t = Frame->Thistriangles.begin(); t != Frame->Thistriangles.end(); t++)
	{
		glm::vec4 v[3];
		v[0] = mvp * t->vertices[0];
		v[1] = mvp * t->vertices[1];
		v[2] = mvp * t->vertices[2];
		t->setVertex(0, v[0]);
		t->setVertex(1, v[1]);
		t->setVertex(2, v[2]);
	}
}
