#pragma once

class MessageData;

class MessageComponent
{
private:
	std::unordered_map<std::string, std::function<void(MessageData)>> messageList;
	typedef std::unordered_map<std::string, std::function<void(MessageData)>>::iterator ListIter;

public:
	MessageComponent();
	~MessageComponent();

	void AddCallBack(std::string Key, std::function<void(MessageData)> func);
	void ExcuteCallBack(std::string key, MessageData data);
	void DeleteCallBack(std::string Key);
};

