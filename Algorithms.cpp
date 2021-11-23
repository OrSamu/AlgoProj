#include "Algorithms.h"


string Algorithms::ListAlgo(Graph inputGraph)
{
	map<int,list<int>> tempList = inputGraph.GetListGraph();
	int** tempMatrice = inputGraph.GetMatriceGraph();
	for (auto const& firstVertice: tempList)
	{
		for (auto const& currentNeighbour : firstVertice.second)
		{
			auto neighbourVerticeIterator = tempList.find(currentNeighbour);
			if (neighbourVerticeIterator != tempList.end())
			{
				list<int> neighbourVertice = neighbourVerticeIterator->second;
				for (auto const& thirdVertice : neighbourVertice)
				{
					if (tempMatrice[thirdVertice][firstVertice.first])
					{
						return (to_string(firstVertice.first) + " " +
							    to_string(neighbourVerticeIterator->first) + " " +
							    to_string(thirdVertice));
					}
				}
			}
		}
	}

	return "NO";
}

string Algorithms::MatriceAlgo(Graph inputGraph)
{
	int** matriceGraph = inputGraph.GetMatriceGraph();
	int size = inputGraph.GetSize() + 1;
	int **gPowIn2 = createEmptyMatrice(size);
	int **gPowIn3 = createEmptyMatrice(size);
	int A = NULL;
	int B = NULL;
	int C = NULL;
	
	string triangle="";
	matriceMultiply(gPowIn2, matriceGraph, matriceGraph,size);
	matriceMultiply(gPowIn3, gPowIn2, matriceGraph,size);

	for (int i = 1; i < size; i++)
	{
		if (gPowIn3[i][i] > 0)
		{
			A = i;
			break;
		}
	}
	if (A != NULL)
	{
		for (int i = 1; i < size; i++)
		{
			if (i != A && gPowIn2[i][A] != 0)
			{
				if (matriceGraph[A][i] != 0)
				{
					B = i;
					for (int j = 0; j < size; j++)
					{
						if (matriceGraph[B][j] != 0 && matriceGraph[j][A] != 0)
						{
							C = j;
							break;
						}
					}
				}
			}
		}
		triangle = to_string(A) + " " + to_string(B) + " " + to_string(C) + " " + to_string(A);
	}
	else triangle = "NO";

	releaseMatrice(gPowIn2, size);
	releaseMatrice(gPowIn3, size);

	return triangle;
}

string Algorithms::AYZAlgo(Graph inputGraph)
{
	return "NO";
}

int** Algorithms::createEmptyMatrice(int size)
{
	int** mul = new int* [size];
	for (int i = 0; i < size; i++)
	{
		mul[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			mul[i][j] = 0;
		}
	}
	return mul;
}

void Algorithms::matriceMultiply(int** res,int** m1, int** m2, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int sum = 0;
			for (int k = 0; k < size; k++) {
				sum += (m1[i][k] * m2[k][j]);
			}
			res[i][j] = sum;
		}
	}
}

void Algorithms::releaseMatrice(int** matriceToRelease, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matriceToRelease[i];
	}
	delete[] matriceToRelease;
}
