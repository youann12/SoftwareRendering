#ifndef SCENE_H
#define SCENE_H

#pragma once
#include "FrameBuffer.h"

class Scene
{
public:
	Scene(FrameBuffer* frame) :f(frame) {};
	~Scene() = default;

	void loadMesh(Mesh m, glm::vec3 position);
	void delMesh(Mesh m);
	void draw(int mode);
	void bindFramebuffer(FrameBuffer* f);

private:

	std::map<Mesh, glm::vec3> ThisMeshes;
	FrameBuffer* f;
	
};
#endif // !SCENE_H
