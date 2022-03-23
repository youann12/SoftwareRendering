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
	//vout.normal = v.normal;
	//vout.Texcoord = v.Texcoord;
	vout.position = v.position;
	vout.windowPos = view * v.position;

	return vout;
}

glm::vec3 Shader::FragmentShader(Vout v)
{
	glm::vec3 color = v.color;
	return color;
}
