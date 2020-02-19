#include "stdafx.h"
#include "StateMessage.h"

StateMessage::StateMessage()
{
}

StateMessage::~StateMessage()
{
	SafeDelete(state);
}
