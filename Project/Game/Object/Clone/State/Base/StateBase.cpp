#include "stdafx.h"
#include "StateBase.h"

StateBase::StateBase(Object * target)
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
