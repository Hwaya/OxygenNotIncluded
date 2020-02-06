#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix(POINTFLOAT pos, POINTFLOAT scale, float radian)
{
	rotation = radian;
	position = pos;
	scaleValue = scale;

	matrix = rotate = D2D1::Matrix3x2F::Identity();
	translate = D2D1::Matrix3x2F::Translation(pos.x, pos.y);
	SetScale(scale.x, scale.y);
	SetRotate(radian);
	CalculateMatrix();
}

void Matrix::SetScale(POINTFLOAT inputScale)
{
	scale = D2D1::Matrix3x2F::Scale(inputScale.x, inputScale.y);
	CalculateMatrix();
}

void Matrix::SetScale(float x, float y)
{
	scale = D2D1::Matrix3x2F::Scale(x, y);
	CalculateMatrix();
}

void Matrix::SetScale(float x)
{
	scale = D2D1::Matrix3x2F::Scale(x, x);
	CalculateMatrix();
}

void Matrix::SetRotate(float radian)
{
	rotation = radian;
	rotate = D2D1::Matrix3x2F::Rotation((float)radian * (180.0 / M_PI));
}

void Matrix::SetRotate(float radian, float x, float y)
{
	rotation = radian;
	rotate = D2D1::Matrix3x2F::Rotation((float)radian * (180.0 / M_PI), D2D1::Point2F(x, y));
	CalculateMatrix();
}

void Matrix::SetPosition(float x, float y)
{
	position = { x,y };
	translate = D2D1::Matrix3x2F::Translation(x, y);
	CalculateMatrix();
}

void Matrix::SetPosition(float x)
{
	position = { x,x };
	translate = D2D1::Matrix3x2F::Translation(x, x);
	CalculateMatrix();
}
