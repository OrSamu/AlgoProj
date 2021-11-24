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

void utils::matriceMultiply(int** res, int** m1, int** m2, int size)
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

void utils::releaseMatrice(int** matriceToRelease, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matriceToRelease[i];
	}
	delete[] matriceToRelease;
}
