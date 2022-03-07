#include "Triangle.h"
#include <vector>

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


	std::vector<glm::vec3> framebuffer;

	FrameBuffer( int w ,  int h );
	~FrameBuffer() = default;
	std::vector<glm::vec3>& frame_buffer() { return framebuffer; }
	void setPoint(int x, int y, glm::vec3 color);
	void setLine(glm::vec2 start, glm::vec2 end, glm::vec3 color);
	void clearColor(glm::vec3 color);
	void loadData(float *data, int *ind);
	void loadData(vertexData* data);
};
