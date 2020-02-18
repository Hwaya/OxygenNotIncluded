#include "stdafx.h"
#include "Camera.h"

SINGLETONCPP(Camera)

void Camera::Initialize()
{
	cameraSpeed = _defaultCameraSpeed;
	view.SetPosition(0.f, 0.f);
	view.SetRotate(0.f);
	view.SetScale(WINSIZEX, WINSIZEY);
	inverseView.SetPosition(0.f, 0.f);
	view.SetRotate(0.f);
	view.SetScale(WINSIZEX, WINSIZEY);
}

void Camera::Update()
{
	if (KEYBOARD.Stay(VK_LEFT))
	{
		view.SetPosition(view.GetPosition().x - cameraSpeed, view.GetPosition().y);
		inverseView.SetPosition(inverseView.GetPosition().x + cameraSpeed, inverseView.GetPosition().y);
	}
	if (KEYBOARD.Stay(VK_UP))
	{
		view.SetPosition(view.GetPosition().x, view.GetPosition().y - cameraSpeed);
		inverseView.SetPosition(inverseView.GetPosition().x, inverseView.GetPosition().y + cameraSpeed);
	}
	if (KEYBOARD.Stay(VK_RIGHT))
	{
		view.SetPosition(view.GetPosition().x + cameraSpeed, view.GetPosition().y);
		inverseView.SetPosition(inverseView.GetPosition().x - cameraSpeed, inverseView.GetPosition().y);
	}
	if (KEYBOARD.Stay(VK_DOWN))
	{
		view.SetPosition(view.GetPosition().x, view.GetPosition().y + cameraSpeed);
		inverseView.SetPosition(inverseView.GetPosition().x, inverseView.GetPosition().y - cameraSpeed);
	}

	if(MOUSE.GetPosition().x < 50.f)
	{
		view.SetPosition(view.GetPosition().x - cameraSpeed, view.GetPosition().y);
		inverseView.SetPosition(inverseView.GetPosition().x + cameraSpeed, inverseView.GetPosition().y);
	}
	if (MOUSE.GetPosition().y < 50.f)
	{
		view.SetPosition(view.GetPosition().x, view.GetPosition().y - cameraSpeed);
		inverseView.SetPosition(inverseView.GetPosition().x, inverseView.GetPosition().y + cameraSpeed);

	}
	if (MOUSE.GetPosition().x > WINSIZEX - 50.f)
	{
		view.SetPosition(view.GetPosition().x + cameraSpeed, view.GetPosition().y);
		inverseView.SetPosition(inverseView.GetPosition().x - cameraSpeed, inverseView.GetPosition().y);

	}
	if (MOUSE.GetPosition().y > WINSIZEY - 50.f)
	{
		view.SetPosition(view.GetPosition().x, view.GetPosition().y + cameraSpeed);
		inverseView.SetPosition(inverseView.GetPosition().x, inverseView.GetPosition().y - cameraSpeed);

	}
}

void Camera::SetView(D2DPOINTF pos, D2DPOINTF size, D2DPOINTF scale)
{
}