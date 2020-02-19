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
		oxEfficiency = _o2Rate;
		dcEfficiency = _co2Rate;
		peeEfficiency = _peeRate;
		structEfficiency = _structSpeed;
		miningEfficiency = _miningSpeed;
		speed = _speed;
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
	//현재정보
	//행동
	//긍정효과
	//부정효과
	//상태슬롯1
	//상태슬롯2
	//상태슬롯3
	//상태슬롯4
	//상태슬롯5
public:
	Clone(std::string name, D2DPOINTF pos, D2DPOINTF size, float rotation);
	~Clone();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
};

