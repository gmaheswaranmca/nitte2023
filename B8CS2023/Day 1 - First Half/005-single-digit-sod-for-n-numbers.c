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
void read_numbers(int N, unsigned long int numbers[]) {
	for (int I = 0; I < N; I++)//read_numbers
	{
		scanf("%ld", &numbers[I]);
	}
}
void find_sod_4_numbers(int N, unsigned long int numbers[], 
							   unsigned long int sum[]) {
	for (int I = 0; I < N; I++)//
	{
		sum[I] = single_digit_sod(numbers[I]);
	}

}
void print_sods(int N, unsigned long int sum[]) {
	for (int I = 0; I < N; I++)//
	{
		printf("%ld ", sum[I]);
	}
}
int main()
{
	int N;
	unsigned long int numbers[1000];
	unsigned long int sum[1000];
	scanf("%d", &N);
	read_numbers(N, numbers);
	find_sod_4_numbers(N, numbers, sum);
	print_sods(N, sum);
	return 0;
}

