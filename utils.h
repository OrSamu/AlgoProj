#pragma once
class utils
{
public:
	static int** createEmptyMatrice(int size);
	static void matriceMultiply(int** res, int** m1, int** m2, int size);
	static void releaseMatrice(int** matriceToRelease, int size);

private:

};

