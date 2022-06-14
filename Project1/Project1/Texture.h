#ifndef TEXTURE_H
#define TEXTURE_H


#pragma once
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>



class Texture
{
public:
	int				width;
	int				height;
	int				channels;
	unsigned char*	data;

	Texture() = default;
	//Texture(const std::string& p)
	//{
	//	data = stbi_load(p.c_str(), &width, &height, &channels, 0);
	//};

	~Texture() = default;

	void		loadTexture(const std::string& p);
	glm::vec3	sample2D(const glm::vec2& texcoord);
	glm::vec3	getColor(int x, int y);
};
#endif // !TEXTURE_H
