#pragma once
#include<list>
#include<map>
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

public:
	Graph(Edge* edges, int numOfVertice, int numOfEdges);
	~Graph();
	map<int, list<int>> GetListGraph();
	int** GetMatriceGraph();
	int GetSize()
	{
		return verticesNum;
	}
};

