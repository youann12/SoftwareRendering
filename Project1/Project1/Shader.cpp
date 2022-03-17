#include "Shader.h"


void Shader::setModel(glm::mat4 m)
{
	model = m;
}

void Shader::setView(int ox, int oy, int width, int height)
{
	glm::mat4 v = glm::mat4(1.0f);
	v[0][0] = width / 2.0f;
	v[3][0] = ox + (width / 2.0f);
	v[1][1] = -height / 2.0f;
	v[3][1] = oy + (height / 2.0f);
	view = v;
}

void Shader::setProjection(glm::mat4 p)
{
	projection = p;
}

Vout Shader::vertexShader(vertex v)
{
	Vout vout;
	glm::mat4x4 mvp = { 0.5,0,0,0,
						0,0.5,0,0,
						0,0,0.5,0,
						0,0,0,1 }; //projection * view * model;
	vout.color = v.color;
	vout.normal = v.normal;
	vout.Texcoord = v.Texcoord;
	vout.position = v.position;
	vout.windowPos = view * v.position;

	return vout;
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

glm::vec3 Shader::FragmentShader(vertex v)
{
	glm::vec3 color = v.color;
	return color;
}
