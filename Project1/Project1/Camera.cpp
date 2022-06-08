#include "Camera.h"

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(mCameraPos, mCameraPos + mCameraFront, mCameraUp);
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
