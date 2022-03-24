#include "Scene.h"


void Scene::loadMesh(Mesh m, glm::vec3 position)
{
	ThisMeshes.insert(std::pair<Mesh, glm::vec3>(m, position));
}

void Scene::delMesh(Mesh m)
{
	ThisMeshes.erase(m);
}

void Scene::draw(int mode)
{
	std::map < Mesh, glm::vec3>::iterator m;
	for (m = ThisMeshes.begin(); m != ThisMeshes.end(); m++)
	{
		f->draw(mode, m->first);
	}
}

void Scene::bindFramebuffer(FrameBuffer* frame)
{
	f = frame;
}

