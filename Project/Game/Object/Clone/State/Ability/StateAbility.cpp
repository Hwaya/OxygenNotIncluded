#include "stdafx.h"
#include "StateAbility.h"
#include "./Game/Object/Clone/Clone.h"

StateAbilityNone::StateAbilityNone(Object* target)
	:StateBase(target)
{
}

StateAbilityNone::~StateAbilityNone()
{
}

void StateAbilityNone::Begin()
{
}

void StateAbilityNone::Excute()
{
}

void StateAbilityNone::Render()
{
}

void StateAbilityNone::End()
{
}


/* ---------- Positive ---------- */

/* Oxygen */
StateAbilityPositiveOxygen::StateAbilityPositiveOxygen(Object * target)
	:StateBase(target)
{
}

StateAbilityPositiveOxygen::~StateAbilityPositiveOxygen()
{
}

void StateAbilityPositiveOxygen::Begin()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetOldInfo().o2Efficiency = temp->GetInfo().o2Efficiency;
	temp->GetInfo().o2Efficiency -= 25.f;
	SafeDelete(temp);
}

void StateAbilityPositiveOxygen::Excute()
{
}

void StateAbilityPositiveOxygen::Render()
{
}

void StateAbilityPositiveOxygen::End()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetInfo().o2Efficiency = temp->GetOldInfo().o2Efficiency;
	temp->GetOldInfo().o2Efficiency = _o2Rate;
}

/* Mining */

StateAbilityPositiveMining::StateAbilityPositiveMining(Object * target)
	:StateBase(target)
{
}

StateAbilityPositiveMining::~StateAbilityPositiveMining()
{
}

void StateAbilityPositiveMining::Begin()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetOldInfo().miningEfficiency = temp->GetInfo().miningEfficiency;
	temp->GetInfo().miningEfficiency += 5.f;
}

void StateAbilityPositiveMining::Excute()
{
}

void StateAbilityPositiveMining::Render()
{
}

void StateAbilityPositiveMining::End()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetInfo().miningEfficiency = temp->GetOldInfo().miningEfficiency;
	temp->GetOldInfo().miningEfficiency = _miningSpeed;
}

/* Speed */
StateAbilityPositiveSpeed::StateAbilityPositiveSpeed(Object * target)
	:StateBase(target)
{
}

StateAbilityPositiveSpeed::~StateAbilityPositiveSpeed()
{
}

void StateAbilityPositiveSpeed::Begin()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetOldInfo().speed = temp->GetInfo().speed;
	temp->GetInfo().speed += 6.f;
}

void StateAbilityPositiveSpeed::Excute()
{
}

void StateAbilityPositiveSpeed::Render()
{
}

void StateAbilityPositiveSpeed::End()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetInfo().speed = temp->GetOldInfo().speed;
	temp->GetOldInfo().speed = _speed;
}

/* ---------- Negative ---------- */

/* Oxygen */
StateAbilityNegativeOxygen::StateAbilityNegativeOxygen(Object * target)
	:StateBase(target)
{
}

StateAbilityNegativeOxygen::~StateAbilityNegativeOxygen()
{
}

void StateAbilityNegativeOxygen::Begin()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetOldInfo().o2Efficiency = temp->GetInfo().o2Efficiency;
	temp->GetInfo().o2Efficiency += 10.f;
}

void StateAbilityNegativeOxygen::Excute()
{
}

void StateAbilityNegativeOxygen::Render()
{
}

void StateAbilityNegativeOxygen::End()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetInfo().o2Efficiency = temp->GetOldInfo().o2Efficiency;
	temp->GetOldInfo().o2Efficiency = _o2Rate;
}

/* Pee */
StateAbilityNegativePee::StateAbilityNegativePee(Object * target)
	:StateBase(target)
{
}

StateAbilityNegativePee::~StateAbilityNegativePee()
{
}

void StateAbilityNegativePee::Begin()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetOldInfo().peeEfficiency = temp->GetInfo().peeEfficiency;
	temp->GetInfo().peeEfficiency += 1;
}

void StateAbilityNegativePee::Excute()
{
}

void StateAbilityNegativePee::Render()
{
}

void StateAbilityNegativePee::End()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetInfo().peeEfficiency = temp->GetOldInfo().peeEfficiency;
	temp->GetOldInfo().peeEfficiency = _peeRate;
}

/* Speed */
StateAbilityNegativeSpeed::StateAbilityNegativeSpeed(Object * target)
	:StateBase(target)
{
}

StateAbilityNegativeSpeed::~StateAbilityNegativeSpeed()
{
}

void StateAbilityNegativeSpeed::Begin()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetOldInfo().speed = temp->GetInfo().speed;
	temp->GetInfo().speed -= 3;
}

void StateAbilityNegativeSpeed::Excute()
{
}

void StateAbilityNegativeSpeed::Render()
{
}

void StateAbilityNegativeSpeed::End()
{
	Clone* temp = static_cast<Clone*>(owner);
	temp->GetInfo().speed = temp->GetOldInfo().speed;
	temp->GetOldInfo().speed = _speed;
}