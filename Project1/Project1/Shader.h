#pragma once
#include "Triangle.h"
#include "Vout.h"
#include "Texture.h"
#include <vector>

class Shader
{
public:
	Shader() 
	{
		texInd = -1;
	}
	~Shader() = default;
	void		setModel(glm::vec3 pos, glm::vec3 scale, float angle, glm::vec3 axis);
	void		setViewPort(int x, int y, int width, int height);
	void		setView(glm::vec3 pos, glm::vec3 front, glm::vec3 right, glm::vec3 up);
	void		setProjection(float eye_fov, float aspect_ratio, float zNear, float zFar);
	Vout		vertexShader(vertex v);
	glm::vec3	FragmentShader(Vout v);
	int			addTexture(Texture t);
	void		useTexture(int ind);


private:
	int						texInd;
	glm::mat4				model;
	glm::mat4				view;
	glm::mat4				projection;
	glm::mat4				viewport;
	std::vector<Texture>	textures;
	Texture					tex;
};
