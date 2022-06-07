#pragma once
#include "Vout.h"

const float PITCH = 0.0f;
const float YAW = -90.0f;
const float SPEED = 3.5f;
const float SENSITIVITY = 0.1f;


enum Movement
{
	W,
	A,
	S,
	D
};

class Camera
{
public:
	//摄像机属性
	glm::vec3 mCameraPos;
	glm::vec3 mCameraFront;
	glm::vec3 mCameraUp;
	glm::vec3 mCameraRight;
	glm::vec3 mWorldUp;

	//欧拉角
	float mPitch;
	float mYaw;

	//摄像机设置
	float mCameraSpeed;
	float mCameraSensitivity;

	//构造函数
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float pitch = PITCH, float yaw = YAW)
		:mCameraSpeed(SPEED), mCameraSensitivity(SENSITIVITY), mCameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
	{
		mCameraPos = position;
		mWorldUp = up;
		mPitch = pitch;
		mYaw = yaw;
		updateCameraVectors();
	}

	//得到view矩阵
	glm::mat4 GetViewMatrix();
	//按键摄像机运动
	void ProcessKeyboard(Movement direction, float deltaTime);
	//鼠标摄像机转动
	void MoveMouse(float xoffset, float yoffset);

private:
	//更新摄像机坐标
	void updateCameraVectors();
};