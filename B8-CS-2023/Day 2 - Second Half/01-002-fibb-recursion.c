/*
2. Print 1st N terms of Hemachandra numbers (Fibo sries)
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int fibb(int N)
{
	if (N == 1)
	{
		return 0;
	}
	else if (N == 2) {
		return 1;
	}

	return fibb(N - 1) + fibb(N - 2);
}
int main()
{
	for (int I = 1; I <= 10; I++)
	{
		printf("%d ", fibb(I));
	}

	return 0;
}
