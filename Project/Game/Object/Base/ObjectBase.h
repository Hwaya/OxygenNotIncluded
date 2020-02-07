#pragma once

class Matrix;

class ObjectBase
{
private:
	Matrix* transform;
	D2D1_RECT_F rect;
public:
	ObjectBase(D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation);
	~ObjectBase();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	Matrix* GetTransform() { return transform; }
	D2D1_RECT_F GetRect() { return rect; }
};

