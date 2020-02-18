#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix(D2D1_POINT_2F pos, D2D1_POINT_2F scale, float radian)
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

Matrix::~Matrix()
{
}

void Matrix::SetScale(D2D1_POINT_2F inputScale)
{
	scaleValue = D2DPOINTF(inputScale.x, inputScale.y);
	scale = D2D1::Matrix3x2F::Scale(inputScale.x, inputScale.y);
	CalculateMatrix();
}

void Matrix::SetScale(float x, float y)
{
	scaleValue = D2DPOINTF(x, y);
	scale = D2D1::Matrix3x2F::Scale(x, y);
	CalculateMatrix();
}

void Matrix::SetScale(float x)
{
	scaleValue = D2DPOINTF(x, x);
	scale = D2D1::Matrix3x2F::Scale(x, x);
	CalculateMatrix();

}

void Matrix::SetRotate(float radian)
{
	rotation = radian;
	rotate = D2D1::Matrix3x2F::Rotation((float)radian * (180.f / (float)M_PI));
	CalculateMatrix();
}

void Matrix::SetRotate(float radian, float x, float y)
{
	rotation = radian;
	rotate = D2D1::Matrix3x2F::Rotation((float)radian * (180.f / (float)M_PI), D2D1::Point2F(x, y));
	CalculateMatrix();
}

void Matrix::SetPosition(float x, float y)
{
	position = D2DPOINTF(x, y);
	translate = D2D1::Matrix3x2F::Translation(x, y);
	CalculateMatrix();
}

void Matrix::SetPosition(float x)
{
	position = D2DPOINTF(x, x);
	translate = D2D1::Matrix3x2F::Translation(x, x);
	CalculateMatrix();
}

Matrix Matrix::operator*(const Matrix& other)
{
	Matrix result;
	result.scale = this->scale * other.scale;
	result.rotate = this->rotate * other.rotate;
	result.translate = this->translate * other.translate;
	result.matrix = this->matrix * other.matrix;
	result.position.x = this->position.x + other.position.x;
	result.position.y = this->position.y + other.position.y;
	result.rotation = this->rotation + other.rotation;
	result.scaleValue.x = this->scaleValue.x * other.scaleValue.x;
	result.scaleValue.y = this->scaleValue.y * other.scaleValue.y;

	return result;
}
