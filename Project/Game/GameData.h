#pragma once
#include "./Game/Object/Clone/State/Base/StateBase.h"
#include "./Game/Object/Tile/Node/TileNode.h"

//class TileNode;

struct OrderInfo
{
	PickMode pickMode;
	std::vector<std::pair<PickMode,TileNode*>> orderStorage;
	typedef std::vector<std::pair<PickMode, TileNode*>>::iterator orderIter;

	OrderInfo()
	{
		orderStorage.clear();
		pickMode = PickNone;
	}
};

class GameData
{
private:
	OrderInfo orderInfo;
public:
	GameData();
	~GameData();

	PickMode GetPickMode() { return orderInfo.pickMode; }
	void SetPickMode(PickMode input) { orderInfo.pickMode = input; }

	std::vector<std::pair<PickMode, TileNode*>> GetOrder() { return orderInfo.orderStorage; }
	void AddOrder(PickMode mode, TileNode* tile)
	{
		orderInfo.orderStorage.push_back(std::make_pair(mode, tile));
	}

	void DeleteOrder(TileNode* tile)
	{
		OrderInfo::orderIter iter = orderInfo.orderStorage.begin(),
			end = orderInfo.orderStorage.end();

		for (; iter != end; ++iter)
		{
			if ((*iter).second == tile)
			{
				orderInfo.orderStorage.erase(iter);
				return;
			}
		}
	}
};

