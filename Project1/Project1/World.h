#pragma once
#include "FrameBuffer.h"


class World
{
public:
	int id;

	World();
	~World() = default;

private:

	std::vector<Triangle> Thistriangles;
	std::map<Mesh, glm::vec3> ThisMeshes;
	
	FrameBuffer* f;
	Shader* shader;
	
};