#pragma once
class Mouse
{
	SINGLETONHEADER(Mouse)

private:
	D2DPOINTF position;
	float wheelValue;
	float oldWheelValue;
public:
	void Initialize();

	LRESULT InputProc(UINT msg, WPARAM wParam, LPARAM lParam);
	D2DPOINTF GetPosition() { return position; }
};

#define MOUSE Mouse::Get()
