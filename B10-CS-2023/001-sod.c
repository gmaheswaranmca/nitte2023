#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

unsigned long int sum_of_digits(unsigned long int M)
{
    unsigned long int S = 0L;
    while (M > 0L)
    {
        int D = (int)M % 10;
        S += D;
        M /= 10;
    }
    return S;
}
int main()
{
    unsigned long int N;
    scanf("%ld", &N);
    printf("%ld", sum_of_digits(N));
    return 0;
}
