#include <opencv2/opencv.hpp>
#include "Triangle.h"
#include <vector>
#include "Shader.h"

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
	int width;
	int height;
	std::vector<Triangle> Thistriangles;
	
	std::vector<glm::vec3> framebuffer;
	

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
	void setLine(glm::vec2 start, glm::vec2 end, glm::vec3 color);
	void clearColor(glm::vec3 color);
	void loadData(float data[], int ind[], int numVertices, int numTriangles);
	void loadData(vertexData* data);
	void draw(int mode);
private:
	Shader *shader;
	void drawTriangle(Vout v1, Vout v2, Vout v3);
	void drawUpTriangle(Vout v1, Vout v2, Vout v3);
	void drawDownTriangle(Vout v1, Vout v2, Vout v3);
	void scanLine(Vout v1, Vout v2);
};
