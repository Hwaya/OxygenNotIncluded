#pragma once

class Matrix;
class Object
{
protected:
	std::string name;
	Matrix* transform;
	D2D1_RECT_F rect;

	bool isActive;
	bool isShow;

	float alpha;
	float lifeTime;
public:
	Object(std::string inputName, D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation);
	virtual ~Object();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	const std::string& GetName() { return name; }
	Matrix* GetTransform() { return transform; }
	D2D1_RECT_F GetRect() { return rect; }
	bool& GetActive() { return isActive; }
	bool& GetShow() { return isShow; }
	float& GetAlpha() { return alpha; }
	float& GetLifeTime() { return lifeTime; }

	void SetActive(bool input) { isActive = input; }
	void SetAlpha(float input)
	{
		input > 0.f ? (input > 1.f ? alpha = 1.f : alpha = input) : alpha = 0.f;
	}
};

