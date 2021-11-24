#include "Algorithms.h"


string Algorithms::ListAlgo(Graph inputGraph)
{
	map<int, list<int>> tempList = inputGraph.GetListGraph();
	int** tempMatrice = inputGraph.GetMatriceGraph();
	for (auto const& firstVertice : tempList)
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

string Algorithms::MatriceAlgo(int **inputMatrice,int size,map<int,int> dictinoary)
{
	int** gPowIn2 = utils::createEmptyMatrice(size);
	int** gPowIn3 = utils::createEmptyMatrice(size);
	int A = NULL;
	int B = NULL;
	int C = NULL;

	string triangle = "";
	utils::matriceMultiply(gPowIn2, inputMatrice, inputMatrice, size);
	utils::matriceMultiply(gPowIn3, gPowIn2, inputMatrice, size);

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
				if (inputMatrice[A][i] != 0)
				{
					B = i;
					for (int j = 0; j < size; j++)
					{
						if (inputMatrice[B][j] != 0 && inputMatrice[j][A] != 0)
						{
							C = j;
							break;
						}
					}
				}
			}
		}
		if (!dictinoary.empty())
		{
			A = dictinoary.find(A)->second;
			B = dictinoary.find(B)->second;
			C = dictinoary.find(C)->second;
		}
		triangle = to_string(A) + " " + to_string(B) + " " + to_string(C);
	}
	else triangle = "NO";

	utils::releaseMatrice(gPowIn2, size);
	utils::releaseMatrice(gPowIn3, size);

	return triangle;
}

string Algorithms::AYZAlgo(Graph inputGraph, int delta)
{
	int** matrice = inputGraph.GetMatriceGraph();
	int numOfVartices = inputGraph.GetSize();
	int* varticesRankArr = inputGraph.GetVerticesRank();
	int smallKodkods = 0;
	for (int currV = 1; currV < numOfVartices + 1; currV++)
	{
		if (varticesRankArr[currV] <= delta)
		{
			smallKodkods++;
			vector<int> wList, uList;
			for (int j = 1; j < numOfVartices + 1; j++)
			{
				if (matrice[j][currV] != 0)
				{
					uList.push_back(j);
				}
				if (matrice[currV][j] != 0)
				{
					wList.push_back(j);
				}
			}
			for (int currW : wList)
			{
				for (int currU : uList)
				{
					if (matrice[currW][currU] != 0)
					{
						return (to_string(currU) + " " +
							to_string(currV) + " " +
							to_string(currW));
					}
				}
			}
			uList.clear();
			wList.clear();
		}

	}

	int deltaGraphSize = numOfVartices - smallKodkods + 1;
	int** deltaGraph = utils::createEmptyMatrice(deltaGraphSize);
	map<int, int> dictinoary = inputGraph.CreateDeltaGraph(deltaGraph, delta);
	string triangle = MatriceAlgo(deltaGraph, deltaGraphSize, dictinoary);
	utils::releaseMatrice(deltaGraph, deltaGraphSize);
	
	return triangle;
}