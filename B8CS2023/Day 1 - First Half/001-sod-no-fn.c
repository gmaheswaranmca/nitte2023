#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int main()
{
	unsigned long int N, M;
	scanf("%ld", &N);

	unsigned long int S = 0L;
	M = N;
	while (M > 0L)
	{
		int d = (int)M % 10;
		S += d;
		M /= 10;
	}

	printf("%ld", S);
	return 0;
}

