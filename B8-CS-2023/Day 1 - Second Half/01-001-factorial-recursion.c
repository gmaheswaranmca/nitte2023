/*
1. Find Factorial of a number using recursive program.

5! = 5 x 4 x 3 x 2 x 1
5! = 5 x 4!
4! = 4 x 3!
3! = 3 x 2!
2! = 2 x 1!
1! = 1
0! = 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int find_fact(int N)
{
	if (N == 1 || N == 0) {
		return 1;
	}
	return N * find_fact(N - 1);
}
int main()
{
	printf("%d", find_fact(5));

	return 0;
}