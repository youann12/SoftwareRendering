#include "Shader.h"
#include <iostream>
#define MY_PI 3.1415926535


void Shader::setModel(glm::vec3 pos, glm::vec3 scale, float angle, glm::vec3 axis)
{
	angle = angle * MY_PI / 180.0f;
	glm::mat4 rotationM = glm::mat4(1.0f);
	rotationM = glm::rotate(rotationM, angle, axis);

	glm::mat4 scaleM =
	  { scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1 };

	glm::mat4 translateM =
	{	1, 0, 0, pos.x,
		0, 1, 0, pos.y,
		0, 0, 1, pos.z,
		0, 0, 0, 1 };
	
	model = translateM * rotationM * scaleM;
}

void Shader::setViewPort(int x, int y, int width, int height)
{
	glm::mat4 v = glm::mat4(1.0f);
	v[0][0] = width / 2.0f;
	v[3][0] = x + (width / 2.0f);
	v[1][1] = -height / 2.0f;
	v[3][1] = y + (height / 2.0f);
	viewport = v;
}

void Shader::setView(glm::vec3 pos, glm::vec3 front, glm::vec3 right, glm::vec3 up)
{
	//view = glm::lookAt(glm::vec3{ 0,0,10 }, glm::vec3{ 0.0f, 0.0f, -1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f });
	
	view = glm::mat4(1.0f);
	view[0][0] = right.x;
	view[1][0] = right.y;
	view[2][0] = right.z;
	view[3][0] = -glm::dot(right, pos);
	view[0][1] = up.x;
	view[1][1] = up.y;
	view[2][1] = up.z;
	view[3][1] = -glm::dot(up, pos);
	view[0][2] = -front.x;
	view[1][2] = -front.y;
	view[2][2] = -front.z;
	view[3][2] = glm::dot(front, pos);
}


void Shader::setProjection(float eye_fov, float aspect_ratio, float zNear, float zFar)
{
	glm::mat4 result = glm::mat4(0.0f);
	const float tanHalfFov = tan(eye_fov * 0.5f);
	result[0][0] = 1.0f / (aspect_ratio * tanHalfFov);
	result[1][1] = 1.0f / (tanHalfFov);
	result[2][2] = -(zFar + zNear) / (zFar - zNear);
	result[2][3] = -1.0f;
	result[3][2] = (-2.0f * zNear * zFar) / (zFar - zNear);

	projection = result;
	//projection = glm::perspective(eye_fov, aspect_ratio, zNear, zFar);
	//zFar = -zFar;
	//zNear = -zNear;

	//float t = tan(eye_fov / 2 / 180 * MY_PI) * (-zNear);
	//float b = -1 * t;
	//float r = t * aspect_ratio;
	//float l = -1 * r;

	//glm::mat4 ortho1 =
	//{ 
	//	2 / (r - l), 0, 0, 0,
	//	0, 2 / (t - b), 0, 0,
	//	0,0,2 / (zNear - zFar),0,
	//	0,0,0,1
	//};

	//glm::mat4 ortho2 =
	//{
	//	1,0,0, 0,
	//	0,1,0,0,
	//	0,0,1,-1 * (zNear - zFar) / 2,
	//	0,0,0,1
	//};

	//glm::mat4 ortho = ortho1 * ortho2;

	//glm::mat4 transz =
	//{
	//	1, 0, 0, 0,
	//	0, 1, 0, 0,
	//	0, 0, 1, 0,
	//	0, 0, 0, 1
	//};

	//glm::mat4 persp =
	//{
	//	zNear,0,0,0,
	//	0,zNear,0,0,
	//	0,0,zNear + zFar,-1 * zNear * zFar,
	//	0,0,1,0
	//};

	//projection = transz * ortho * persp;
}

void PerspectiveDivision(Vout & v) {
	v.windowPos /= v.windowPos.w;
	v.windowPos.w = 1.0f;
	v.windowPos.z = (v.windowPos.z + 1.0) * 0.5;
}

Vout Shader::vertexShader(vertex v)
{
	Vout vout;
	glm::mat4x4 mvp = projection * view * model;
	vout.color = v.color;
	//vout.normal = v.normal;
	//vout.Texcoord = v.Texcoord;
	vout.position = v.position;
	vout.windowPos = mvp * v.position;
	PerspectiveDivision(vout);
	vout.windowPos = viewport * vout.windowPos;

	return vout;
}

glm::vec3 Shader::FragmentShader(Vout v)
{
	glm::vec3 color = v.color;
	return color;
}
