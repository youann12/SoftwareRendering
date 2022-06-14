#ifndef VOUT_H
#define VOUT_H

#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Vout
{
public:

	glm::vec4 position;
	//glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 Texcoord;
	glm::vec4 windowPos;
	float z;

	Vout()	= default;
	~Vout() = default;

	static Vout lerp(Vout v1, Vout v2, float weight);

private:
	
	static glm::vec4 Lerp(const glm::vec4& v1, const glm::vec4& v2, float weight) {
		return (1.0f - weight) * v1 + weight * v2;
	}
	static glm::vec3 Lerp(const glm::vec3& v1, const glm::vec3& v2, float weight) {
		return (1.0f - weight) * v1 + weight * v2;
	}
	static glm::vec2 Lerp(const glm::vec2& v1, const glm::vec2& v2, float weight) {
		return (1.0f - weight) * v1 + weight * v2;
	}
	static float Lerp(const float& v1, const float& v2, float weight) {
		return (1.0f - weight) * v1 + weight * v2;
	}
};
#endif // !VOUT_H
