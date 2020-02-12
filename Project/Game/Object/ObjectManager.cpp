#include "stdafx.h"
#include "ObjectManager.h"
#include "./Game/Object/Base/Object.h"

SINGLETONCPP(ObjectManager)

void ObjectManager::Initialize()
{
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
