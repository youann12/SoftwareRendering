#pragma once
#include "Triangle.h"
#include <vector>

struct vertexData
{
	glm::vec4 location;
	glm::vec3 color;
	//glm::vec3 normal;
	//glm::vec3 texcoord;
};

class Mesh
{
public:
	Mesh() = default;
	~Mesh() = default;
	void loadData(float data[], int ind[], int numVertices, int numTriangles);
private:
	std::vector<Triangle> Thistriangles;
};