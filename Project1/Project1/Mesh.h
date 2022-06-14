#ifndef MESH_H
#define MESH_H


#pragma once
#include "Triangle.h"
#include <vector>
struct vertexData
{
	glm::vec4 location;
	//glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 texcoord;
};


class Mesh
{
public:
	Mesh() = default;
	~Mesh() = default;
	void loadData(float data[], int ind[], int numVertices, int numTriangles);

	bool operator<(const Mesh& m1)const
	{
		if (Thistriangles.size() < m1.Thistriangles.size())
			return true;
		else
			return false;
	}

	std::vector<Triangle> Thistriangles;
};

#endif // !MESH_H
