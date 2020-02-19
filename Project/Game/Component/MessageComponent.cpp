#include "stdafx.h"
#include "MessageComponent.h"
#include "./Game/Message/Base/MessageData.h"

MessageComponent::MessageComponent()
{
}

MessageComponent::~MessageComponent()
{
}

void MessageComponent::AddCallBack(std::string Key, std::function<void(MessageData)>func)
{
	messageList.insert(make_pair(Key, func));
}

void MessageComponent::ExcuteCallBack(std::string key, MessageData data)
{
	ListIter finder = messageList.find(key);

	if (finder != messageList.end())
	{
		finder->second(data);
	}
}

void MessageComponent::DeleteCallBack(std::string Key)
{
	messageList.erase(Key);
}
