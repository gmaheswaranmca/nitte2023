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
    unsigned long int N, M;
    scanf("%ld", &N);
    unsigned long int S = 0L;
    M = N;
    S = single_digit_sod(M);

    printf("%ld", S);
    return 0;
}
