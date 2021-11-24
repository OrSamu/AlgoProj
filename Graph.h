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
	void CreateList(Edge* edges, int numOfEdges);
	void CreateMatrice(Edge* edges, int numOfVertice, int numOfEdges);
	int *verticesRank;


public:
	Graph(Edge* edges, int numOfVertice, int numOfEdges);
	~Graph();
	map<int, list<int>> GetListGraph();
	int** GetMatriceGraph();
	void filterVertices(Edge* edges, int numOfVertice, int numOfEdges);
	int CreateDeltaGraph(int** output, int delta);
	int GetSize()
	{
		return verticesNum;
	}
	int* GetVerticesRank()
	{
		return verticesRank;
	}
};

