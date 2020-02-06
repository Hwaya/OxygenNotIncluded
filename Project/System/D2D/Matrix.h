#pragma once
class Matrix
{
private:
	D2D1::Matrix3x2F rotate;
	D2D1::Matrix3x2F scale;
	D2D1::Matrix3x2F translate;
	D2D1::Matrix3x2F matrix;

	POINTFLOAT position;
	float rotation;
	POINTFLOAT scaleValue;

public:
	Matrix(POINTFLOAT pos, POINTFLOAT scale = { 1,1 }, float radian = 0.f);

	void CalculateMatrix()
	{
		matrix = scale * rotate * translate;
	}

	D2D1::Matrix3x2F GetMatrix() { return matrix; }
	POINTFLOAT GetPosition() { return position; }
	float GetRotation() { return rotation; }

	void SetScale(POINTFLOAT inputScale);
	void SetScale(float x, float y);
	void SetScale(float x);

	void SetRotate(float radian);
	void SetRotate(float radian, float x, float y);

	void SetPosition(float x, float y);
	void SetPosition(float x);
};

