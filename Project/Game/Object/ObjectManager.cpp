#include "stdafx.h"
#include "ObjectManager.h"
#include "./Game/Object/Base/Object.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Initialize()
{
	objectMap.clear();
}

void ObjectManager::Release()
{
	MapIter mapIter = objectMap.begin();
	for (; mapIter != objectMap.end(); mapIter++)
	{
		VecIter vecIter= (*mapIter).second.begin();
		for (; vecIter != (*mapIter).second.end(); vecIter++)
		{
			(*vecIter)->Release();
			SafeDelete(*vecIter);
			vecIter = (*mapIter).second.erase(vecIter);
		}
		mapIter = objectMap.erase(mapIter);
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
			Matrix relative = RENDER.RenderSet(*(*vecIter)->GetTransform(), true, true);
			if (relative.GetPosition().x > -relative.GetScale().x &&
				relative.GetPosition().y > -relative.GetScale().y &&
				relative.GetPosition().x < WINSIZEX + relative.GetScale().x &&
				relative.GetPosition().y < WINSIZEY + relative.GetScale().y)
			{
				(*vecIter)->Update();
			}
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
			Matrix relative = RENDER.RenderSet(*(*vecIter)->GetTransform(), true, true);
			if (relative.GetPosition().x > -relative.GetScale().x &&
				relative.GetPosition().y > -relative.GetScale().y &&
				relative.GetPosition().x < WINSIZEX + relative.GetScale().x &&
				relative.GetPosition().y < WINSIZEY + relative.GetScale().y)
			{
				(*vecIter)->Render();
			}
		}
	}
}

void ObjectManager::MakeNewVector(std::string name, Object * input)
{
	ObjectVector newStorage;
	newStorage.push_back(input);
	objectMap.insert(make_pair(name, newStorage));
}
