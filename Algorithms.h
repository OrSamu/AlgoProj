#pragma once
#include <string>
#include "Graph.h"

/// <summary>
/// Static Algorithms class
/// </summary>
class Algorithms
{
public:
	static string ListAlgo(Graph inputGraph);
	static string MatriceAlgo(Graph inputGraph);
	static string AYZAlgo(Graph inputGraph);
	static int** createEmptyMatrice(int size);
	static void releaseMatrice(int** matriceToRelease, int size);
	static void matriceMultiply(int** res, int** m1, int** m2, int size);
	};