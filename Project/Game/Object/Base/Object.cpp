#include "stdafx.h"
#include "Object.h"

Object::Object(std::string inputName, D2D1_POINT_2F pos, D2D1_POINT_2F size, bool ui = false, float rotation = 0.f)
{
	name = inputName;
	transform = new Matrix(pos, size, rotation);
	rect = D2D1::RectF(
		pos.x - size.x / 2.f, 
		pos.y - size.y / 2.f, 
		pos.x + size.x / 2.f, 
		pos.y + size.y / 2.f);

	isActive = true;
	isShow = true;
	alpha = 1.f;
	lifeTime = 0.f;

	isUI = ui;
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
	bool a = RENDER.IsDebugMode();
	int b = 0;
	if (RENDER.IsDebugMode())
	{
		if (isUI)
		{
			RENDER.DrawRectangle(rect);
		}
		else{
			Matrix temp = RENDER.RenderSet(*transform, true, true);
			D2DRECTF rc = MakeRect(
				temp.GetPosition().x,
				temp.GetPosition().y,
				temp.GetScale().x,
				temp.GetScale().y
			);
			RENDER.DrawRectangle(rc);
		}
	}
}
