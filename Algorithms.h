#pragma once
#include <string>
#include <vector>
#include "utils.h"
#include "Graph.h"

using namespace std;

/// <summary>
/// Static Algorithms class
/// </summary>
class Algorithms
{
public:
	static string ListAlgo(Graph inputGraph);
	static string MatriceAlgo(int** inputMatrice, int size, map<int, int> dictinoary);
	static string AYZAlgo(Graph inputGraph, int delta);
	};