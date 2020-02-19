#include "stdafx.h"
#include "StateBase.h"
#include "./Game/Object/Clone/Clone.h"

StateBase::StateBase(Clone * target)
	:owner(target)
{
	Begin();
}

StateBase::~StateBase()
{
	End();
}

void StateBase::Begin()
{
}

void StateBase::Excute()
{
}

void StateBase::End()
{
}
