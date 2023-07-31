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

unsigned long int single_digit_sod(unsigned long int M)
{
    unsigned long int S = 0L;
    do
    {

        S = sum_of_digits(M);
        M = S;
    } while (!(S >= 0 && S <= 9));
    return S;
}

int main()
{
    int N;
    scanf("%d", &N);
    unsigned long int numbers[1000];
    unsigned long int sum[1000];
    for (int I = 0; I < N; I++)
    {
        scanf("%ld", &numbers[I]);
    }

    for (int I = 0; I < N; I++)
    {
        sum[I] = single_digit_sod(numbers[I]);
    }

    for (int I = 0; I < N; I++)
    {
        printf("%ld ", sum[I]);
    }

    return 0;
}
