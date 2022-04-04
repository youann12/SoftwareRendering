#pragma once
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class Texture
{
public:
	int width;
	int height;
	int channels;
	unsigned char* data;

	Texture() = default;
	Texture(const std::string& p)
	{
		unsigned char* data = new unsigned char;
		data = stbi_load(p.c_str(), &width, &height, &channels, 0);
	};

	~Texture() 
	{
		if (data)
			delete data;
	};

	void loadTexture(const std::string& p)
	{
		data = stbi_load(p.c_str(), &width, &height, &channels, 0);
	};

};