#pragma once
#include <string>
#include <vector>
#include "utils.h"
#include "Graph.h"

/// <summary>
/// Static Algorithms class
/// </summary>
class Algorithms
{
public:
	static string ListAlgo(Graph inputGraph);
	static string MatriceAlgo(int** inputMatrice, int size);
	static string AYZAlgo(Graph inputGraph, int delta);
	static void releaseMatrice(int** matriceToRelease, int size);
	static void matriceMultiply(int** res, int** m1, int** m2, int size);
	};