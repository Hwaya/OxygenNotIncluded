#include "stdafx.h"
#include "StateManager.h"

StateManager::StateManager(Object * inputOwner)
	:owner(inputOwner)
{
}

StateManager::~StateManager()
{
}

void StateManager::Initialize()
{
	for (int i = StateBegin; i != StateEnd; ++i)
	{
		if ((StateKind)i != StateBegin && (StateKind)i != StateEnd)
		{
			mapState.insert(std::make_pair((StateKind)i, nullptr));
		}
	}
	SetState(StateActivity, 1);
	SetState(StatePositive, 1);
	SetState(StateNegative, 1);
	SetState(StateBuff1, 1);
	SetState(StateBuff2, 1);
	SetState(StateBuff3, 1);
	SetState(StateBuff4, 1);
	SetState(StateBuff5, 1);
}

void StateManager::Release()
{
	MapIter iter = mapState.begin();
	for (; iter != mapState.end(); ++iter)
	{
		SafeDelete((*iter).second);
		mapState.erase(iter);
		--iter;
	}
}

void StateManager::Update()
{
	MapIter iter = mapState.begin(), end = mapState.end();
	for (; iter != end; ++iter)
	{
		(*iter).second->Excute();
	}
}

void StateManager::Render()
{
	MapIter iter = mapState.begin(), end = mapState.end();
	for (; iter != end; ++iter)
	{
		(*iter).second->Render();
	}
}