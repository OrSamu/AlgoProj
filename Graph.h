#pragma once
#include<list>
#include<map>
#include "utils.h"
#include "Edge.h"
using namespace std;

class Graph
{
private:
	int verticesNum;
	map<int,list<int>> Neighbours_List;
	int** Neighbours_Matrice;
	void CreateDataStructures(Edge* edges, int numOfVertice, int numOfEdges);
	int *verticesRank;


public:
	Graph(Edge* edges, int numOfVertice, int numOfEdges);
	~Graph();
	map<int, list<int>> GetListGraph();
	int** GetMatriceGraph();
	void FilterEdge(int source, int dest);
	void CreateDeltaGraph(int** output, int delta);
	int GetSize()
	{
		return verticesNum;
	}
	int* GetVerticesRank()
	{
		return verticesRank;
	}
};

