#include <opencv2/opencv.hpp>
#include "Triangle.h"
#include <vector>
#include "Shader.h"
#include "Mesh.h"
#include <map>

//struct vertexData
//{
//	glm::vec4 location;
//	glm::vec3 color;
//	//glm::vec3 normal;
//	//glm::vec3 texcoord;
//};


class FrameBuffer
{
public:
	FrameBuffer(int w, int h, Shader* s) :shader(s) {
		width = w;
		height = h;
		framebuffer.resize((double)this->width * (double)this->height);
		depthbuffer.resize((double)this->width * (double)this->height, 1.0f);
		clearColor(glm::vec3{ 0.0f, 0.0f, 0.0f });
		shader = s;
	};
	FrameBuffer() = default;
	~FrameBuffer() = default;

	void	setPoint(int x, int y, glm::vec3 color);
	void	clearColor(glm::vec3 color);
	void	draw(int mode, Mesh m);
	float	getDepth(const int& x, const int& y);
	void	writeDepth(const int& x, const int& y, const float& depth);
	std::vector<glm::vec3>& frame_buffer() { return framebuffer; }

private:
	int	width;
	int height;
	
	Shader* shader;
	
	std::vector<glm::vec3>		framebuffer;
	std::vector<float>			depthbuffer;


	void drawTriangle(const Vout &v1, const Vout &v2, const Vout &v3);
	void drawUpTriangle(const Vout &v1, const Vout &v2, const Vout &v3);
	void drawDownTriangle(const Vout &v1, const Vout &v2, const Vout &v3);
	void scanLine(const Vout &v1, const Vout &v2);
};
