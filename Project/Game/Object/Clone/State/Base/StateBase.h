#pragma once
class StateBase
{
private:
	Object* owner;
public:
	StateBase(Object* target);
	virtual ~StateBase();

	virtual void Begin() = 0;
	virtual void Excute() = 0;
	virtual void End() = 0;
};

