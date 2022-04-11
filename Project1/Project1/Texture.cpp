#include "Texture.h"

void Texture::loadTexture(const std::string& p)
{
	data = stbi_load(p.c_str(), &width, &height, &channels, 0);
}

glm::vec3 Texture::sample2D(const glm::vec2& texcoord)
{
	//GL_REPEAT
	float x = texcoord.x - (float)floor(texcoord.x);
	float y = texcoord.y - (float)floor(texcoord.y);
	return getColor(x * (width - 1), y * (height - 1));
}

glm::vec3 Texture::getColor(int x, int y)
{
	if (x <0 || x > width || y < 0 || y> height)
		return glm::vec3(0, 0, 0);
	int xy = channels * (y * width + x);
	float b, g, r;
	b = *(data + xy + 2);
	g = *(data + xy + 1) ;
	r = *(data + xy);
	return glm::vec3(b / 255, g /255 , r / 255);
}
