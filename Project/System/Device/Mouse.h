#pragma once
class Mouse
{
	SINGLETONHEADER(Mouse)

private:
	D2DPOINTF position;
	float wheelValue;
	float oldWheelValue;
	float wheel;
public:
	void Initialize();

	LRESULT InputProc(UINT msg, WPARAM wParam, LPARAM lParam);
	D2DPOINTF GetPosition() { return position; }
	float GetWheelValue() { return wheel; }
};

#define MOUSE Mouse::Get()