#pragma once

class Clone;

class StateBase
{
private:
	Clone* owner;
public:
	StateBase(Clone* target);
	virtual ~StateBase();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

