#include "Mesh.h"

void Mesh::loadData(float data[], int ind[], int numVertices, int numTriangles)
{
	std::vector<vertexData> vertices;
	// load vertex data, include vertices attributes
	for (int i = 0; i < numVertices; i += 8)
	{
		vertexData v;
		v.location	= glm::vec4{ data[i], data[i + 1], data[i + 2], 1.0f };
		//v.color		= glm::vec3{ data[i + 3], data[i + 4], data[i + 5] };
		v.normal = glm::vec3{ data[i + 3], data[i + 4], data[i + 5] };
		v.texcoord	= glm::vec2{ data[i + 6], data[i + 7] };
		vertices.push_back(v);
	}

	// according to index array and vertices array to construct triangle
	for (int i = 0; i < numTriangles; i += 3)
	{
		glm::vec4 tVertices[3]	= { vertices[ind[i]].location,	vertices[ind[i + 1]].location,	vertices[ind[i + 2]].location };
		//glm::vec3 tColors[3]	= { vertices[ind[i]].color,		vertices[ind[i + 1]].color,		vertices[ind[i + 2]].color };
		glm::vec3 tNormal[3]	= { vertices[ind[i]].normal,		vertices[ind[i + 1]].normal,		vertices[ind[i + 2]].normal };
		glm::vec2 tTexCoord[3]  = { vertices[ind[i]].texcoord,	vertices[ind[i + 1]].texcoord,	vertices[ind[i + 2]].texcoord };
		Triangle t = Triangle(tVertices, tNormal, tTexCoord);
		Thistriangles.push_back(t);
	}
}
