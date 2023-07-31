#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
unsigned long int sod(unsigned long int M)
{
	unsigned long int S = 0L;
	while (M > 0L)
	{
		int d = (int)M % 10;
		S += d;
		M /= 10;
	}
	return S;
}
unsigned long int single_digit_sod(unsigned long int M)
{
	unsigned long int S = 0L;
	do {
		S = sod(M);
		M = S;
	} while (!(0 <= S && S <= 9));
	return S;
}
int main()
{
	unsigned long int N, M;
	scanf("%ld", &N);

	unsigned long int S = 0L;
	M = N;
	S = single_digit_sod(M);
	printf("%ld", S);
	return 0;
}

