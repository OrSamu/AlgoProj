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
	return "NO";
}

string Algorithms::AYZAlgo(Graph inputGraph)
{
	return "NO";
}
