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

glm::vec4 Shader::vertexShader(vertex v)
{
	glm::mat4x4 mvp = { 0.5,0,0,0,
						0,0.5,0,0,
						0,0,0.5,0,
						0,0,0,1 }; //projection * view * model;
	return mvp * v.position;
	//Frame->framebuffer;
	//std::vector<Triangle>::iterator t;
	//for (t = Frame->Thistriangles.begin(); t != Frame->Thistriangles.end(); t++)
	//{
	//	glm::vec4 v[3];
	//	v[0] = mvp * t->vertices[0].position;
	//	v[1] = mvp * t->vertices[1].position;
	//	v[2] = mvp * t->vertices[2].position;
	//	t->setPos(0, v[0]);
	//	t->setPos(1, v[1]);
	//	t->setPos(2, v[2]);
	//}
}
