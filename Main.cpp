#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "Edge.h"
#include "Graph.h"
#include "Algorithms.h"

using namespace std;

int inputEdges(FILE* inputFile, Edge* edges_p, int numOfVertices);

int main(int argc, char* argv[])
{
	int algoId;
	int numOfVertices;
	int numOfEdges;
	string triangleName;
	Edge* edges_p;
	FILE* inputFile;
	ofstream outputFile;
	Algorithms algoTool;
	

	inputFile = fopen(argv[1], "r");

	fscanf(inputFile, "%d", &algoId);
	fscanf(inputFile, "%d", &numOfVertices);

	if (algoId < 1 || numOfVertices < 1 || algoId > 4)
	{
		throw std::invalid_argument("invalid input");
	}

	edges_p = (Edge*)malloc(sizeof(Edge) * numOfVertices * numOfVertices);

	numOfEdges = inputEdges(inputFile, edges_p, numOfVertices);
	fclose(inputFile);

	(Edge*)realloc(edges_p, sizeof(Edge) * numOfEdges);

	Graph inputGraph(edges_p, numOfVertices, numOfEdges);
	
	switch (algoId)
	{
	case 1:
	{
		triangleName = algoTool.ListAlgo(inputGraph);
		break;
	}
	case 2:
	{
		triangleName = algoTool.MatriceAlgo(inputGraph.GetMatriceGraph(),inputGraph.GetSize()+1);
		break;
	}
	case 3:
	{
		int delta = pow(numOfEdges, 0.5);
		triangleName = algoTool.AYZAlgo(inputGraph,delta);
		break;
	}
	case 4:
	{
		algoTool.ListAlgo(inputGraph);
		algoTool.MatriceAlgo(inputGraph.GetMatriceGraph(), inputGraph.GetSize() + 1);
		triangleName = algoTool.AYZAlgo(inputGraph, pow(numOfEdges, 0.5));
		break;
	}
	default:
		break;
	}
	
	outputFile.open(argv[2], ios_base::trunc);
	
	outputFile << triangleName;
	
	outputFile.close();
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