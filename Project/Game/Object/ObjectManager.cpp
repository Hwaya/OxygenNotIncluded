#include "stdafx.h"
#include "ObjectManager.h"
#include "./Game/Object/Base/Object.h"

SINGLETONCPP(ObjectManager)

void ObjectManager::Initialize()
{
	objectMap.clear();
}

void ObjectManager::Release()
{
	MapIter mapIter = objectMap.begin();
	for (; mapIter != objectMap.end(); ++mapIter) 
	{
		VecIter vecIter= (*mapIter).second.begin();
		for (; vecIter != (*mapIter).second.end(); ++vecIter)
		{
			(*vecIter)->Release();
			SafeDelete(*vecIter);
			(*mapIter).second.erase(vecIter);
			--vecIter;
		}
		objectMap.erase(mapIter);
		--mapIter;
	}
}

void ObjectManager::Update()
{
	MapIter mapIter = objectMap.begin(), mapEnd = objectMap.end();
	for (; mapIter != mapEnd; ++mapIter)
	{
		VecIter vecIter = (*mapIter).second.begin(), vecEnd = (*mapIter).second.end();
		for (; vecIter != vecEnd; ++vecIter)
		{
			(*vecIter)->Update();
		}
	}
}

void ObjectManager::Render()
{
	MapIter mapIter = objectMap.begin(), mapEnd = objectMap.end();
	for (; mapIter != mapEnd; ++mapIter)
	{
		VecIter vecIter = (*mapIter).second.begin(), vecEnd = (*mapIter).second.end();
		for (; vecIter != vecEnd; ++vecIter)
		{
			(*vecIter)->Render();
		}
	}
}

void ObjectManager::MakeNewVector(std::string name, Object * input)
{
	ObjectVector newStorage;
	newStorage.push_back(input);
	objectMap.clear();

	
	objectMap.insert(make_pair(name, newStorage));
}
