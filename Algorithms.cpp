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
	int** gPowIn2, **gPowIn3;
	int A = NULL;
	int B = NULL;
	int C = NULL;
	int size = inputGraph.GetSize() + 1;
	string triangle="";
	gPowIn2 = multiply(matriceGraph, matriceGraph,size);
	gPowIn3 = multiply(matriceGraph, gPowIn2,size);
	for (int i = 1; i <= size; i++)
	{
		if (gPowIn3[i][i] > 0)
		{
			A = gPowIn3[i][i];
			break;
		}
	}
	if (A != NULL)
	{
		for (int i = 1; i <= size; i++)
		{
			if (i != A && gPowIn2[i][A] != 0)
			{
				if (matriceGraph[A][i] != 0)
				{
					B = i;
					for (int j = 0; j <= size; j++)
					{
						if (matriceGraph[B][j] != 0 && matriceGraph[j][A] != 0)
						{
							C = j;
						}
					}
				}
			}
		}
		triangle = to_string(A) + " " + to_string(B) + " " + to_string(C) + " " + to_string(A);
	}
	else triangle = "NO";

	releaseMatrice(gPowIn2,size);
	releaseMatrice(gPowIn3,size);

	return triangle;
}

string Algorithms::AYZAlgo(Graph inputGraph)
{
	return "NO";
}

int** multiply(int** a, int** b, int size)
{
	int** mul = new int* [size];
	for (int i = 0; i <= size; i++)
	{
		mul[i] = new int[size];
		for (int j = 0; j < 3; j++)
		{
			mul[i][j] = 0;
			for (int k = 0; k < 3; k++)
				mul[i][j] += a[i][k] * b[k][j];
		}
	}
	return mul;
}

void releaseMatrice(int **matriceToRelease,int size)
{
	for (int i = 0; i <= size; i++)
	{
		delete[] matriceToRelease[i];
	}
	delete[] matriceToRelease;
}
