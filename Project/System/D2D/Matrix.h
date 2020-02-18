#pragma once
class Matrix
{
private:
	D2D1::Matrix3x2F rotate;
	D2D1::Matrix3x2F scale;
	D2D1::Matrix3x2F translate;
	D2D1::Matrix3x2F matrix;

	D2D1_POINT_2F position;
	float rotation;
	D2D1_POINT_2F scaleValue;

public:
	Matrix(D2D1_POINT_2F pos = { 0.f, 0.f }, D2D1_POINT_2F scale = { 1.f,1.f }, float radian = 0.f);
	~Matrix();

	void CalculateMatrix()
	{
		matrix = scale * rotate * translate;
	}

	D2D1::Matrix3x2F GetMatrix() { return matrix; }
	D2D1_POINT_2F GetPosition() { return position; }
	D2D1_POINT_2F GetScale() { return scaleValue; }
	float GetRotation() { return rotation; }


	void SetScale(D2D1_POINT_2F inputScale);
	void SetScale(float x, float y);
	void SetScale(float x);

	void SetRotate(float radian);
	void SetRotate(float radian, float x, float y);

	void SetPosition(float x, float y);
	void SetPosition(float x);

	Matrix operator *(const Matrix& other);

	Matrix GetInvert()
	{
		if (matrix.IsInvertible())
		{

		}
	}
};

