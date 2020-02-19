#pragma once

#include "./Game/Object/Clone/State/Base/StateBase.h"

class Clone;

class StateAbilityNone : public StateBase
{
public:
	StateAbilityNone(Object* target);
	virtual ~StateAbilityNone();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};

/* ---------- Positive ---------- */

/* Oxygen */
class StateAbilityPositiveOxygen : public StateBase
{
public:
	StateAbilityPositiveOxygen(Object* target);
	virtual ~StateAbilityPositiveOxygen();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};

/* Mining */
class StateAbilityPositiveMining : public StateBase
{
public:
	StateAbilityPositiveMining(Object* target);
	virtual ~StateAbilityPositiveMining();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};

/* Speed */
class StateAbilityPositiveSpeed : public StateBase
{
public:
	StateAbilityPositiveSpeed(Object* target);
	virtual ~StateAbilityPositiveSpeed();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};


/* ---------- Negative ---------- */

/* Oxygen */
class StateAbilityNegativeOxygen : public StateBase
{
public:
	StateAbilityNegativeOxygen(Object* target);
	virtual ~StateAbilityNegativeOxygen();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};

/* Pee */
class StateAbilityNegativePee : public StateBase
{
public:
	StateAbilityNegativePee(Object* target);
	virtual ~StateAbilityNegativePee();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};

/* Speed */
class StateAbilityNegativeSpeed : public StateBase
{
public:
	StateAbilityNegativeSpeed(Object* target);
	virtual ~StateAbilityNegativeSpeed();

	virtual void Begin();
	virtual void Excute();
	virtual void Render();
	virtual void End();
};