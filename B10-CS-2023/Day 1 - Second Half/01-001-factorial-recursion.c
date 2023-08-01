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
