#include "Camera.h"

glm::mat4 Camera::GetViewMatrix()
{
	glm::mat4 view = glm::mat4(1.0f);
	view[0][0] = mCameraRight.x;
	view[1][0] = mCameraRight.y;
	view[2][0] = mCameraRight.z;
	view[3][0] = -glm::dot(mCameraRight, mCameraPos);
	view[0][1] = mCameraUp.x;
	view[1][1] = mCameraUp.y;
	view[2][1] = mCameraUp.z;
	view[3][1] = -glm::dot(mCameraUp, mCameraPos);
	view[0][2] = -mCameraFront.x;
	view[1][2] = -mCameraFront.y;
	view[2][2] = -mCameraFront.z;
	view[3][2] = glm::dot(mCameraFront, mCameraPos);
	return view;
}

void Camera::ProcessKeyboard(Movement direction, float deltaTime)
{
	float velocity = mCameraSpeed * deltaTime;
	if (direction == W)
		mCameraPos += mCameraFront * velocity;
	if (direction == S)
		mCameraPos -= mCameraFront * velocity;
	if (direction == A)
		mCameraPos -= mCameraRight * velocity;
	if (direction == D)
		mCameraPos += mCameraRight * velocity;
}

void Camera::MoveMouse(float xoffset, float yoffset)
{
	xoffset *= mCameraSensitivity;
	yoffset *= mCameraSensitivity;

	mYaw += xoffset;
	mPitch += yoffset;

	if (mPitch > 89.0f)
		mPitch = 89.0f;
	if (mPitch < -89.0f)
		mPitch = -89.0f;
	updateCameraVectors();
}

void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(mPitch)) * cos(glm::radians(mYaw));
	front.y = sin(glm::radians(mPitch));
	front.z = cos(glm::radians(mPitch)) * sin(glm::radians(mYaw));
	mCameraFront = glm::normalize(front);
	mCameraRight = glm::normalize(glm::cross(mCameraFront, mWorldUp));
	mCameraUp = glm::normalize(glm::cross(mCameraRight, mCameraFront));
}
