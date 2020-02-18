#pragma once
class Object;
class ObjectManager
{
	SINGLETONHEADER(ObjectManager)
private:
	typedef std::unordered_map<std::string, std::vector<Object*>>::iterator MapIter;
	typedef std::vector<Object*> ObjectVector;
	typedef std::vector<Object*>::iterator VecIter;
	std::unordered_map<std::string, std::vector<Object*>> objectMap;

public:
	void Initialize();
	void Release();
	void Update();
	void Render();

	void MakeNewVector(std::string name, Object* input);

	template<typename A>
	Object* NewObject(std::string inputName, D2DPOINTF pos, D2DPOINTF size, float rotation = 0.f)
	{
		A* testCase = new A(inputName, pos, size, rotation);
		if (dynamic_cast<Object*>(testCase) != nullptr)
		{
			Object* tempUpCast = static_cast<Object*>(testCase);

			if (objectMap.size() > 0)
			{
				MapIter finder = objectMap.find(typeid(A).name());

				if (finder != objectMap.end())
				{
					objectMap[typeid(A).name()].push_back(tempUpCast);
				}
				else
				{
					MakeNewVector(typeid(A).name(), tempUpCast);
				}
			}
			else
			{
				MakeNewVector(typeid(A).name(), tempUpCast);
			}
			return tempUpCast;
		}
		return nullptr;
	}

	template<typename A>
	void DeleteObject(Object* obj)
	{
		MapIter finder = objectMap.find(typeid(A).name());
		if (finder != objectMap.end())
		{
			ObjectVector iter = objectMap[typeid(A).name()].begin(), end = objectMap[typeid(A).name()].end();
			for (; iter != end; ++iter)
			{
				if (*iter == obj)
				{
					(*iter)->Release();
					SafeDelete(*iter);
					objectMap[typeid(A).name()].erase(iter);
					return;
				}
			}
		}
	}
	
	template<typename A>
	Object* FindObject(Object* obj)
	{
		MapIter finder = objectMap.find(typeid(A).name());
		if (finder != objectMap.end()) 
		{
			ObjectVector iter = objectMap[typeid(A).name()].begin(), end = objectMap[typeid(A).name()].end();
			for (; iter != end; ++iter)
			{
				if ((*iter) == obj)
				{
					return *iter;
				}
			}
		}
	}
};

#define OBJECT ObjectManager::Get()