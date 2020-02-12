#include "stdafx.h"
#include "Object.h"

Object::Object(std::string inputName, D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation = 0.f)
{
	name = inputName;
	transform = new Matrix(pos, size, rotation);
	rect = D2D1::RectF(
		pos.x - size.x / 2.f, 
		pos.y - size.y / 2.f, 
		pos.x + size.x / 2.f, 
		pos.y + size.y / 2.f);
}

Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Release()
{
}

void Object::Update()
{
}

void Object::Render()
{
	if (RENDER.IsDebugMode())
	{
		RENDER.DrawRectangle(rect);
	}
}
