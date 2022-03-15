#pragma once
#include "FrameBuffer.h"

class Shader
{
public:
	Shader(FrameBuffer* f): Frame(f){ }
	~Shader() = default;
	void setModel(glm::mat4 m);
	void setView(glm::mat4 v);
	void setProjection(glm::mat4 p);
	void vertexTransform();
	


private:
	FrameBuffer* Frame;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	
};