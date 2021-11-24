#include "utils.h"

int** utils::createEmptyMatrice(int size)
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