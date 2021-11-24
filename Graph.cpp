#include "Graph.h"

Graph::Graph(Edge* edges, int numOfVertice, int numOfEdges)
{
	verticesNum = numOfVertice;
	CreateList(edges, numOfEdges);
	CreateMatrice(edges, numOfVertice, numOfEdges);
	filterVertices(edges, numOfVertice, numOfEdges);
}

Graph::~Graph()
{
	//for (int i = 0; i < Neighbours_List.size(); i++)
	//{
	//	Neighbours_List[i].~list();
	//}
	//
	//for (int i = 0; i < verticesNum; ++i)
	//{
	//	delete[] Neighbours_Matrice[i];
	//}
	//delete[] Neighbours_Matrice;
}

map<int, list<int>> Graph::GetListGraph()
{
	return Neighbours_List;
}

int** Graph::GetMatriceGraph()
{
	return Neighbours_Matrice;
}

void Graph::CreateList(Edge* edges, int numOfEdges)
{
	int currSource, currDest;
	for (int i = 0; i < numOfEdges; i++)
	{
		currSource = edges[i].GetSource();
		currDest = edges[i].GetDest();

		if (Neighbours_List.find(edges[i].GetSource()) == Neighbours_List.end())
		{
			// Source not found
			list<int> listOfNeighbours;
			listOfNeighbours.push_back(currDest);
			Neighbours_List.insert(make_pair(currSource, listOfNeighbours));
		}
		else
		{
			Neighbours_List[currSource].push_back(currDest);
		}
	}
}

void Graph::CreateMatrice(Edge* edges, int numOfVertices, int numOfEdges)
{


	int allocateSize = numOfVertices + 1;
	Neighbours_Matrice = new int*[allocateSize];
	int currSource, currDest;

	for (int i = 0; i < allocateSize; i++)
	{
		Neighbours_Matrice[i] = new int[allocateSize];
		for (int j = 0; j < allocateSize; j++)
		{
			Neighbours_Matrice[i][j] = 0;
		}
	}

	for (int i = 0; i < numOfEdges; i++)
	{
		currSource = edges[i].GetSource();
		currDest = edges[i].GetDest();

		Neighbours_Matrice[currSource][currDest] = 1;
	}
}

void Graph::filterVertices(Edge* edges, int numOfVertice, int numOfEdges)
{
	verticesRank = new int[numOfVertice + 1]{};
	int source, dest;
	for (int i = 0; i < numOfEdges; i++)
	{
		source = edges[i].GetSource();
		dest = edges[i].GetDest();
		verticesRank[source]++;
		verticesRank[dest]++;
	}
}

int Graph::CreateDeltaGraph(int** output,int delta) 
{
	map<int, int> gTag2gMap;
	int shift = 0;
	for (int i = 1; i < verticesNum+1; i++)
	{
		if (verticesRank[i] <= delta)
		{
			shift++;
		}
		else
		{
			gTag2gMap.insert(make_pair(i - shift, i));
		}
	}
	
	for (pair<int, int> currSource : gTag2gMap)
	{
		for (pair<int, int> currDest : gTag2gMap)
		{
			output[currSource.first][currDest.first] = Neighbours_Matrice[currSource.second][currDest.second];
		}
	}

	return gTag2gMap.size();
}
