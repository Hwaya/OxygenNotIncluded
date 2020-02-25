#pragma once

class PathNode
{
private:
	PathNode* parentsNode;
	POINT myIndex;
	int total;
	int cost;
	int heuristic;
	int depth;
public:
	PathNode(PathNode* parents, int x, int y)
		:parentsNode(parents), myIndex({ x,y })
	{}
	~PathNode() {}

	PathNode* GetParentsNode() { return parentsNode; }
	POINT GetIndex() { return myIndex; }
	int GetTotal() { return total; }
	int GetCost() { return cost; }
	int GetHeuristic() { return heuristic; }
	int GetDepth() { return depth; }

	void SetParentsNode(PathNode* input) { parentsNode = input; }
	void SetIndex(int x, int y) { myIndex = { x,y }; }
	void SetTotal(int input) { total = input; }
	void SetCost(int input) { cost = input; }
	void SetHeuristic(int input) { heuristic = input; }
	void SetDepth(int input) { depth = input; }
};

class AstarComponent
{
private:
	POINT startIndex;
	POINT endIndex;
	
	PathNode* resultNode;

	std::vector<PathNode*> openList;
	std::vector<PathNode*> closeList;
	typedef std::vector<PathNode*>::iterator ListIter;

	typedef std::vector<POINT> Path;
	typedef std::vector<POINT>::iterator ResultIter;

	void ProcessFind(PathNode* currentNode);
public:
	AstarComponent();
	~AstarComponent();

	void Initialize();

	POINT* PathFinder(int x, int y, int dx, int dy);

	PathNode* isOnArray(std::vector<PathNode*> array, PathNode* value);
};

