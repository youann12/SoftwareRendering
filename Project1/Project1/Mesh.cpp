#include "mesh.h"

void Mesh::loadData(float data[], int ind[], int numVertices, int numTriangles)
{
	std::vector<vertexData> vertices;
	// load vertex data, include vertices attributes
	for (int i = 0; i < numVertices; i += 6)
	{
		vertexData v;
		v.location = glm::vec4{ data[i], data[i + 1], data[i + 2], 1.0f };
		v.color = glm::vec3{ data[i + 3], data[i + 4], data[i + 5] };
		vertices.push_back(v);
	}

	// according to index array and vertices array to construct triangle
	for (int i = 0; i <= numTriangles; i += 3)
	{
		glm::vec4 tVertices[3] = { vertices[i].location, vertices[i + 1].location, vertices[i + 2].location };
		glm::vec3 tColors[3] = { vertices[i].color, vertices[i + 1].color, vertices[i + 2].color };
		Triangle t = Triangle(tVertices, tColors);
		Thistriangles.push_back(t);
	}
}
