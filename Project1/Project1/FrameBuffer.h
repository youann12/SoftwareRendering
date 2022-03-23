#include <opencv2/opencv.hpp>
#include "Triangle.h"
#include <vector>
#include "Shader.h"
//#include "Mesh.h"
#include <map>

struct vertexData
{
	glm::vec4 location;
	glm::vec3 color;
	//glm::vec3 normal;
	//glm::vec3 texcoord;
};



class FrameBuffer
{
public:
	FrameBuffer(int w, int h, Shader* s) :shader(s) {
		width = w;
		height = h;
		framebuffer.resize((double)this->width * (double)this->height);
		clearColor(glm::vec3{ 0.0f, 0.0f, 0.0f });
		shader = s;
	};
	FrameBuffer();
	~FrameBuffer() = default;
	std::vector<glm::vec3>& frame_buffer() { return framebuffer; }
	void setPoint(int x, int y, glm::vec3 color);
	void clearColor(glm::vec3 color);
	void loadData(float data[], int ind[], int numVertices, int numTriangles);
	//void loadMesh(Mesh m, glm::vec3 position);
	//void delMesh(Mesh m);
	void draw(int mode);

private:
	int width;
	int height;

	std::vector<Triangle> Thistriangles;
	//std::map<Mesh, glm::vec3> ThisMeshes;

	std::vector<glm::vec3> framebuffer;
	Shader *shader;

	void drawTriangle(const Vout &v1, const Vout &v2, const Vout &v3);
	void drawUpTriangle(const Vout &v1, const Vout &v2, const Vout &v3);
	void drawDownTriangle(const Vout &v1, const Vout &v2, const Vout &v3);
	void scanLine(const Vout &v1, const Vout &v2);
};
