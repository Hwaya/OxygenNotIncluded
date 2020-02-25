#include "stdafx.h"
#include "AstarComponent.h"
#include "Game/Object/Tile/Node/TileNode.h"

AstarComponent::AstarComponent()
{
}

AstarComponent::~AstarComponent()
{
}

void AstarComponent::Initialize()
{
	ListIter iter = openList.begin();
	while (iter != openList.end())
	{
		SafeDelete(*iter);
		openList.erase(iter);
	}
	openList.clear();

	iter = closeList.begin();
	while (iter != closeList.end())
	{
		SafeDelete(*iter);
		closeList.erase(iter);
	}
	closeList.clear();

	SafeDelete(resultNode);
}

POINT*  AstarComponent::PathFinder(int x, int y, int dx, int dy)
{
	startIndex = { x,y };
	endIndex = { dx, dy };

	Initialize();

	if (ComparePoint({ x,y }, { dx,dy }) ||
		x < 0 || y < 0 || dx < 0 || dy < 0 ||
		x > TILE->GetMapSize().x || y > TILE->GetMapSize().y ||
		dx > TILE->GetMapSize().x || dy > TILE->GetMapSize().y)
	{
		return nullptr;
	}

	if (x >= 0 && x <= TILE->GetMapSize().x && y >= 0 && y <= TILE->GetMapSize().y)
	{
		ProcessFind(new PathNode(nullptr, x, y));
	}

	POINT* path = new POINT[resultNode->GetDepth()];
	PathNode* tempNode = resultNode;
	for (int i = resultNode->GetDepth(); i>=0; --i)
	{
		path[i] = tempNode->GetIndex();
		tempNode = tempNode->GetParentsNode();
	}
	SafeDelete(tempNode);

	return path;
}



//result = goal + huristic
void AstarComponent::ProcessFind(PathNode* currentNode)
{
	int tempX = currentNode->GetIndex().x;
	int tempY = currentNode->GetIndex().y;

	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (tempX + j < 0 || tempX + j > TILE->GetMapSize().y || tempY + i < 0 || tempY + i > TILE->GetMapSize().y)
			{
				continue;
			}
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (TILE->Tile(tempX + j, tempY + i)->GetAttribute() != AttributeLock)
			{
				float cost = (currentNode == nullptr ? 0 : currentNode->GetCost()) + (i * j != 0 ? 14 : 10);
				float heuristic = (abs(endIndex.x - (tempX + j))  + abs(endIndex.y - (tempY + i))) * 10;
				float total = cost + heuristic;

				PathNode* newNode = new PathNode(currentNode, tempX + j, tempY + i);
				newNode->SetCost(cost);
				newNode->SetHeuristic(heuristic);
				newNode->SetTotal(total);
				newNode->SetDepth(currentNode == nullptr ? 0 : currentNode->GetDepth() + 1);
				
				if (isOnArray(closeList, newNode) != nullptr) continue;

				PathNode* temp = isOnArray(openList, newNode);

				if (temp != nullptr)
				{
					if (temp->GetTotal() <= total)
					{
						temp->SetParentsNode(currentNode);
						temp->SetTotal(total);
						temp->SetCost(cost);
						temp->SetHeuristic(heuristic);
					}
				}
				else
				{
					openList.push_back(newNode);
				}
			}
			else
			{
				PathNode* newNode = new PathNode(currentNode, tempX + j, tempY + i);

				closeList.push_back(newNode);
			}
		}
	}

	ListIter iter = openList.begin(), end = openList.end(), pointIter;
	PathNode* minNode = nullptr;
	for (; iter != end; ++iter)
	{
		if (minNode == nullptr)
		{
			minNode = *iter;
			pointIter = iter;
		}
		else
		{
			if (minNode->GetTotal() > (*iter)->GetTotal())
			{
				minNode = *iter;
				pointIter = iter;
			}
		}
	}
	if (minNode != nullptr)
	{
		openList.erase(pointIter);
	}

	if (ComparePoint(minNode->GetIndex(), endIndex))
	{
		resultNode = minNode;
		return;
	}
	else
	{
		closeList.push_back(minNode);
		ProcessFind(minNode);
	}
}

PathNode * AstarComponent::isOnArray(std::vector<PathNode*> array, PathNode * value)
{
	ListIter iter = array.begin(), end = array.end();

	for (; iter != end; ++iter)
	{
		if (ComparePoint(value->GetIndex(), (*iter)->GetIndex()))
		{
			return *iter;
		}
	}
	return nullptr;
}