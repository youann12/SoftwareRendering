#include "Shader.h"
#include <iostream>
#define MY_PI 3.1415926535

glm::vec3 reflect(glm::vec3 lightDir, glm::vec3 norm);

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
	view = glm::lookAt(glm::vec3{ 0,0,5 }, glm::vec3{ 0.0f, 0.0f, -1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f });
	
	//view = glm::mat4(1.0f);
	//view[0][0] = right.x;
	//view[1][0] = right.y;
	//view[2][0] = right.z;
	//view[3][0] = -glm::dot(right, pos);
	//view[0][1] = up.x;
	//view[1][1] = up.y;
	//view[2][1] = up.z;
	//view[3][1] = -glm::dot(up, pos);
	//view[0][2] = -front.x;
	//view[1][2] = -front.y;
	//view[2][2] = -front.z;
	//view[3][2] = glm::dot(front, pos);
}

void Shader::setCameraView(glm::mat4 camView)
{
	view = camView;
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
	glm::mat4x4 normalTrans = glm::inverse(glm::transpose(model * view));

	vout.windowPos = mvp * v.position;

	glm::vec4 transNormal = glm::vec4(v.normal, 0.0f);
	transNormal = normalize(normalTrans * transNormal);

	vout.z = 1 / vout.windowPos.w;
	//vout.color = v.color * vout.z;
	vout.normal = glm::vec3(transNormal) * vout.z;
	vout.Texcoord = v.Texcoord * vout.z;
	vout.position = v.position * vout.z;


	PerspectiveDivision(vout);
	vout.windowPos = viewport * vout.windowPos;
	//std::cout << "normal before " << v.normal.x << " " << v.normal.y << " " << v.normal.z << " " << std::endl;
	//std::cout << "normal final " << vout.normal.x << " " << vout.normal.y << " " << vout.normal.z << " " << std::endl;

	return vout;
}

glm::vec3 Shader::FragmentShader(Vout v)
{
	glm::vec3 color;
	if (texInd != -1)
	{
		color = tex.sample2D(v.Texcoord);

		glm::vec3 ambient = light.color * light.intensity;
		
		glm::vec3 norm = normalize(v.normal);
		glm::vec3 dir = normalize(light.direction);
		float diff = glm::max(dot(norm, dir), 0.0f);
		glm::vec3 diffuse = diff * light.color;

		float specularStrength = 1;
		glm::vec3 camDir = normalize(camPos - glm::vec3(v.position.x, v.position.y, v.position.z));
		glm::vec3 lightDir = normalize(light.pos - glm::vec3(v.position.x, v.position.y, v.position.z));
		glm::vec3 reflectDir = normalize(reflect(-lightDir, norm));
 		float spec = pow(glm::max(glm::dot(camDir, reflectDir), 0.0f), 64);
		glm::vec3 specular = specularStrength * spec * light.specular;
		
		//if (spec > 0.1)
		//{
		//	std::cout << "sssss£º " << spec << std::endl;
		//}

		color *= (ambient + diffuse + specular);

	}
	else
		color = glm::vec3(0.0f, 0.0f, 0.0f);
	return color;
}

int Shader::addTexture(Texture t)
{
	textures.push_back(t);
	return textures.size();
}

void Shader::useTexture(int ind)
{
	texInd = ind - 1;
	tex = textures[texInd];
}

int Shader::addLight(Light l)
{
	lights.push_back(l);
	return lights.size();
}

void Shader::useLight(int ind)
{
	lightInd = ind - 1;
	light = lights[lightInd];
}

void Shader::setCamPos(glm::vec3 pos)
{
	camPos = pos;
}

glm::vec3 reflect(glm::vec3 lightDir, glm::vec3 norm)
{
	return lightDir - (2.0f * norm * glm::dot(lightDir, norm));
}
