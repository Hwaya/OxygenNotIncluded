#pragma once
#include "./Game/Object/Clone/State/Ability/StateAbility.h"
#include "./Game/Object/Clone/State/Base/StateBase.h"

class StateManager
{
private:
	Object* owner;
	std::unordered_map<StateKind, StateBase*> mapState;
	typedef std::unordered_map<StateKind, StateBase*>::iterator MapIter;
public:
	StateManager(Object* inputOwner);
	~StateManager();

	void Initialize();
	void Release();
	void Update();
	void Render();

	StateBase* GetActivity() { return mapState[StateActivity]; }
	StateBase* GetPositive() { return mapState[StatePositive]; }
	StateBase* GetNegative() { return mapState[StateNegative]; }
	StateBase* GetStateSlot(int index) { return mapState[(StateKind)(index+4)]; }
	StateBase* GetState(StateKind kind) { return mapState[kind]; }

	void SetState(StateKind kind, int index)
	{
		mapState[kind]->End();
		SafeDelete(mapState[kind]);
		mapState[kind] = MakeState(kind, index, owner);
		mapState[kind]->Begin();
	}

	StateBase* MakeState(StateKind kind, int index, Object* owner)
	{
		switch (kind)
		{
		case StateActivity:
			switch ((Activity)index)
			{
			case ActivityIdle:
				break;
			case ActivityMove:
				break;
			case ActivityStruct:
				break;
			case ActivitySleep:
				break;
			case ActivityPee:
				break;
			case ActivityEat:
				break;
			}
			break;
		case StatePositive:
			switch ((Positive)index)
			{
			case PositiveNone:
				return static_cast<StateBase*>(new StateAbilityNone(owner));
				break;
			case PositiveO2:
				return static_cast<StateBase*>(new StateAbilityPositiveOxygen(owner));
				break;
			case PositiveMining:
				return static_cast<StateBase*>(new StateAbilityPositiveMining(owner));
				break;
			case PositiveSpeed:
				return static_cast<StateBase*>(new StateAbilityPositiveSpeed(owner));
				break;
			}
			break;
		case StateNegative:
			switch ((Negative)index)
			{
			case NegativeNone:
				return static_cast<StateBase*>(new StateAbilityNone(owner));
				break;
			case NegativeO2:
				return static_cast<StateBase*>(new StateAbilityNegativeOxygen(owner));
				break;
			case NegativePee:
				return static_cast<StateBase*>(new StateAbilityNegativePee(owner));
				break;
			case NegativeSpeed:
				return static_cast<StateBase*>(new StateAbilityNegativeSpeed(owner));
				break;
			}
			break;
		case StateBuff1:
			switch ((Buff)index)
			{
			case BuffDirty:
				break;
			case BuffCold:
				break;
			case BuffHot:
				break;
			case BuffSick:
				break;
			}
			break;
		case StateBuff2:
			switch ((Buff)index)
			{
			case BuffDirty:
				break;
			case BuffCold:
				break;
			case BuffHot:
				break;
			case BuffSick:
				break;
			}
			break;
		case StateBuff3:
			switch ((Buff)index)
			{
			case BuffDirty:
				break;
			case BuffCold:
				break;
			case BuffHot:
				break;
			case BuffSick:
				break;
			}
			break;
		case StateBuff4:
			switch ((Buff)index)
			{
			case BuffDirty:
				break;
			case BuffCold:
				break;
			case BuffHot:
				break;
			case BuffSick:
				break;
			}
			break;
		case StateBuff5:
			switch ((Buff)index)
			{
			case BuffDirty:
				break;
			case BuffCold:
				break;
			case BuffHot:
				break;
			case BuffSick:
				break;
			}
			break;
		}
	}
};