#ifndef LIGHT_H
#define LIGHT_H
#pragma once
#include "Vout.h"

class Light
{
public:
	glm::vec3 color;
	glm::vec3 direction;
	glm::vec3 pos;
	glm::vec3 specular;


	float intensity;
	Light(
		const glm::vec3& lColor		= glm::vec3( 1.0f, 1.0f, 1.0f ),
		const glm::vec3& lDirection = glm::vec3( 1.0f, 1.0f, 1.0f ),
		const glm::vec3& lPos		= glm::vec3( 3.0f, 3.0f, 3.0f ),
		const glm::vec3& lSpecular	= glm::vec3( 1.0f, 1.0f, 1.0f ),
		const float&	 i			= 0.3f ) :
		pos(lPos),
		color(lColor),
		specular(lSpecular),
		direction(lDirection),
		intensity(i)
	{}
	virtual ~Light(){}
};


#endif // !LIGHT_H
