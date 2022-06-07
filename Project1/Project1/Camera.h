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
	//���������
	glm::vec3 mCameraPos;
	glm::vec3 mCameraFront;
	glm::vec3 mCameraUp;
	glm::vec3 mCameraRight;
	glm::vec3 mWorldUp;

	//ŷ����
	float mPitch;
	float mYaw;

	//���������
	float mCameraSpeed;
	float mCameraSensitivity;

	//���캯��
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float pitch = PITCH, float yaw = YAW)
		:mCameraSpeed(SPEED), mCameraSensitivity(SENSITIVITY), mCameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
	{
		mCameraPos = position;
		mWorldUp = up;
		mPitch = pitch;
		mYaw = yaw;
		updateCameraVectors();
	}

	//�õ�view����
	glm::mat4 GetViewMatrix();
	//����������˶�
	void ProcessKeyboard(Movement direction, float deltaTime);
	//��������ת��
	void MoveMouse(float xoffset, float yoffset);

private:
	//�������������
	void updateCameraVectors();
};