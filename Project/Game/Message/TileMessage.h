#pragma once
#include "./Game/Message/Base/MessageData.h"
#include "./Game/Object/Tile/TileInfo.h"



class TileMessage : public MessageData
{
public:
	TileMessage();
	~TileMessage();

	TileInfo msgInfo;
	float damage;
};

