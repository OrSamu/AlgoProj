#include "Graph.h"

Graph::Graph(Edge* edges, int numOfVertices, int numOfEdges)
{
	verticesNum = numOfVertices;
	CreateDataStructures(edges, numOfVertices,numOfEdges);
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

// release linkedlists
// relase matrice - has already
// release rankedVertica
// use them both

map<int, list<int>> Graph::GetListGraph()
{
	return Neighbours_List;
}

int** Graph::GetMatriceGraph()
{
	return Neighbours_Matrice;
}

void Graph::CreateDataStructures(Edge* edges, int numOfVertices, int numOfEdges)
{
	int currSource, currDest;
	int allocateSize = numOfVertices + 1;

	Neighbours_Matrice = utils::createEmptyMatrice(allocateSize);
	verticesRank = new int[numOfVertices + 1]{};

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

		Neighbours_Matrice[currSource][currDest] = 1;
		FilterEdge(currSource, currDest);
	}
}

void Graph::FilterEdge(int source, int dest)
{
	verticesRank[source]++;
	verticesRank[dest]++;
}

void Graph::CreateDeltaGraph(int** output,int delta) 
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
}
