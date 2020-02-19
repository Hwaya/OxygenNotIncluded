#pragma once

class Clone;

class StateAbilityNone : public StateBase
{
	StateAbilityNone(Clone* target);
	~StateAbilityNone();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

/* ---------- Positive ---------- */

/* Oxygen */
class StateAbilityPositiveOxygen : public StateBase
{
	StateAbilityPositiveOxygen(Object* target);
	~StateAbilityPositiveOxygen();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

/* Mining */
class StateAbilityPositiveMining : public StateBase
{
	StateAbilityPositiveMining(Object* target);
	~StateAbilityPositiveMining();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

/* Speed */
class StateAbilityPositiveSpeed : public StateBase
{
	StateAbilityPositiveSpeed(Object* target);
	~StateAbilityPositiveSpeed();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};


/* ---------- Negative ---------- */

/* Oxygen */
class StateAbilityNegativeOxygen : public StateBase
{
	StateAbilityNegativeOxygen(Object* target);
	~StateAbilityNegativeOxygen();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

/* Pee */
class StateAbilityNegativePee : public StateBase
{
	StateAbilityNegativePee(Object* target);
	~StateAbilityNegativePee();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

/* Speed */
class StateAbilityNegativeSpeed : public StateBase
{
	StateAbilityNegativeSpeed(Object* target);
	~StateAbilityNegativeSpeed();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};