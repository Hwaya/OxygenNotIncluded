#pragma once
#include "stdafx.h"

inline D2DCOLOR MakeColor(float r, float g, float b)
{
	return D2D1::ColorF(r, g, b);
}
inline D2D1_RECT_F MakeRect(float x, float y, float width, float height)
{
	return D2D1::RectF(x - width / 2.f, y - height / 2.f, x + width / 2.f, y + height / 2.f);
}

inline RECT& ToRect(D2DRECTF& d2drect)
{
	RECT tempRect;
	tempRect.left = (LONG)d2drect.left;
	tempRect.top = (LONG)d2drect.top;
	tempRect.right = (LONG)d2drect.right;
	tempRect.bottom = (LONG)d2drect.bottom;

	return tempRect;
}
inline bool PointInRect(float x, float y, D2DRECTF& rc)
{
	return rc.left < x && rc.top < y && rc.right > x && rc.bottom > y;
}
inline bool PointInElipse(float x, float y, D2DELLIPSE& ellipse)
{

}
inline bool RectCollision(D2DRECTF& rect1, D2DRECTF& rect2)
{
	RECT temp1 = ToRect(rect1), temp2 = ToRect(rect2), temp3;
	return IntersectRect(&temp3, &temp1, &temp2);
}
