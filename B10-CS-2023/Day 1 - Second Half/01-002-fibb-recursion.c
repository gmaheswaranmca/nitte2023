#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fibb(int N) {
    if (N == 0)
    {
        return 0;
    }
    else if (N == 1)
    {
        return 1;
    }

    return fibb(N - 1) + fibb(N - 2);
}

int main()
{
    for (int I = 0; I < 10; I++)
    {
        printf("%d ", fibb(I));
    }
    return 0;
}
