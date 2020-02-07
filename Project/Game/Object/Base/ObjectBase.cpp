#include "stdafx.h"
#include "ObjectBase.h"
#include "./System/D2D/Matrix.h"

ObjectBase::ObjectBase(D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation)
{
	transform = new Matrix(pos, size, rotation);
	rect = D2D1::RectF(
		pos.x - size.x / 2.f, 
		pos.y - size.y / 2.f, 
		pos.x + size.x / 2.f, 
		pos.y + size.y / 2.f);
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Initialize()
{
}

void ObjectBase::Update()
{
}

void ObjectBase::Render()
{
	if (RENDER.IsDebugMode())
	{
		RENDER.DrawRectangle(rect);
	}
}
