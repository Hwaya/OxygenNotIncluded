#include "stdafx.h"
#include "StateBase.h"

StateBase::StateBase(Object * target)
	:owner(target)
{
}

StateBase::~StateBase()
{
}

void StateBase::Begin()
{
}

void StateBase::Excute()
{
}

void StateBase::Render()
{

}

void StateBase::End()
{
}
