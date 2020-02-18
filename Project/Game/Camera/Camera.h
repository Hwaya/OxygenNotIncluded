#pragma once

static const float _defaultCameraSpeed = 10.f;

class Camera
{
	SINGLETONHEADER(Camera)
private:
	Matrix view;
	Matrix inverseView;
	float cameraSpeed;
public:
	void Initialize();
	void Update();

	void SetView(D2DPOINTF pos, D2DPOINTF size, D2DPOINTF scale);
	Matrix& GetView() { return view; }
	Matrix& GetInvertView() { return inverseView; }
};

#define CAMERA Camera::Get()