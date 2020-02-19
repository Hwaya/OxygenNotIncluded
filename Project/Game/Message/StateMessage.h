#pragma once
#include "./Game/Message/Base/MessageData.h"
#include "./Game/Object/Clone/State/Base/StateBase.h"
#include "./Game/Object/Clone/State/Ability/StateAbility.h"
//#include "./Game/Object/Clone/State/Activity/"
//#include "./Game/Object/Clone/State/Buff/"

class StateMessage : public MessageData
{
public:
	StateBase* state;
public:
	StateMessage();
	~StateMessage();

	template<typename T>
	void SetState(Object* target)
	{
		state = new T(target);
	}
};

