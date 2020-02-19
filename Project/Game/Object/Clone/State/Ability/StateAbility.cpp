#include "stdafx.h"
#include "StateAbility.h"
#include "./Game/Object/Clone/Clone.h"
#include "./Game/Object/Clone/State/Base/StateBase.h"

StateAbilityNone::StateAbilityNone(Clone* target)
	:StateBase(target)
{
}

StateAbilityNone::~StateAbilityNone()
{
	End();
}

void StateAbilityNone::Begin()
{
	
}

void StateAbilityNone::Excute()
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
}

void StateAbilityPositiveOxygen::Excute()
{
}

void StateAbilityPositiveOxygen::End()
{
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
}

void StateAbilityPositiveMining::Excute()
{
}

void StateAbilityPositiveMining::End()
{
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
}

void StateAbilityPositiveSpeed::Excute()
{
}

void StateAbilityPositiveSpeed::End()
{
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
}

void StateAbilityNegativeOxygen::Excute()
{
}

void StateAbilityNegativeOxygen::End()
{
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
}

void StateAbilityNegativePee::Excute()
{
}

void StateAbilityNegativePee::End()
{
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
}

void StateAbilityNegativeSpeed::Excute()
{
}

void StateAbilityNegativeSpeed::End()
{
}
