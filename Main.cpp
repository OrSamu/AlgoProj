#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Edge.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int inputEdges(FILE* inputFile, Edge* edges_p, int numOfVertices);

int main(int argc, char* argv[])
{
	int algoId;
	int numOfVertices;
	int numOfEdges;
	//TODO: Change to Vector
	Edge* edges_p;

	FILE* inputFile;
	ofstream outputFile;

	inputFile = fopen(argv[1], "r");

	fscanf(inputFile, "%d", &algoId);
	fscanf(inputFile, "%d", &numOfVertices);

	if (algoId < 1 || numOfVertices < 1 || algoId > 4)
	{
		throw std::invalid_argument("invalid input");
	}

	edges_p = (Edge*)malloc(sizeof(Edge) * numOfVertices * numOfVertices);

	numOfEdges = inputEdges(inputFile, edges_p, numOfVertices);

	(Edge*)realloc(edges_p, sizeof(Edge) * numOfEdges);

	switch (algoId)
	{
	case 1:
	{
		NeighborsList(edges_p);
		break;
	}
	case 2:
	{
		NeighborsList(edges_p);
		break;
	}
	default:
		break;
	}
	
	fclose(inputFile);
}

int inputEdges(FILE* inputFile, Edge* edges_p, int numOfVertices)
{
	int counter = 0;
	int t_src, t_dest;

	while (!feof(inputFile))
	{
		fscanf(inputFile, "%d %d ", &t_src, &t_dest);

		if (t_src <= 0 || t_dest <= 0 ||
			t_src > numOfVertices || t_dest > numOfVertices)
		{
			throw std::invalid_argument("invalid input");
		}

		edges_p[counter].SetSource(t_src);
		edges_p[counter].SetDest(t_dest);
		
		counter++;
	}

	return counter;
}