#include "stdafx.h"
#include "Mouse.h"

SINGLETONCPP(Mouse)

void Mouse::Initialize()
{
	position = D2DPOINTF(0.f, 0.f);
	wheelValue = oldWheelValue = 0.f;
	wheel = 50.f;
}

LRESULT Mouse::InputProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_LBUTTONDOWN || msg == WM_MOUSEMOVE)
	{
		position.x = (float)LOWORD(lParam);
		position.y = (float)HIWORD(lParam);
	}

	if (msg == WM_MOUSEWHEEL)
	{
		short inputWheelValue = (short)HIWORD(wParam);

		oldWheelValue = wheelValue;

		wheelValue += (float)inputWheelValue;

		if (wheelValue != oldWheelValue)
		{
			wheel += (_zoomSpeed * (inputWheelValue / abs(inputWheelValue)));
			if (wheel > _maxZoom)
			{
				wheel = _maxZoom;
			}
			else if (wheel < 0)
			{
				wheel = 0;
			}
		}
	}
	return true;
}