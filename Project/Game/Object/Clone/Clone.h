#pragma once

struct CloneInfo
{
	float oxEfficiency;
	float dcEfficiency;
	float peeEfficiency;
	float structEfficiency;
	float miningEfficiency;
	float speed;
	CloneInfo()
	{
		oxEfficiency = 0.f;
		dcEfficiency = 0.f;
		peeEfficiency = 0.f;
		structEfficiency = 0.f;
		miningEfficiency = 0.f;
		speed = 0.f;
	}
};

enum PositiveAbility
{
	PositiveStart,
	PositiveOxygen,
	PositiveHand,
	PositiveLeg,
	PositiveEnd
};

enum NegativeAbility
{
	NegativeStart,
	NegativeOxygen,
	NegativeShit,
	NegativeLeg,
	NegativeEnd
};

class Clone : public Object
{
private:
	//��������
	//�ൿ
	//����ȿ��
	//����ȿ��
	//���½���1
	//���½���2
	//���½���3
	//���½���4
	//���½���5
public:
	Clone(std::string name, D2DPOINTF pos, D2DPOINTF size, float rotation);
	~Clone();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
};

