/* 
	Find smallest and biggest element in an Array 
	-- 
	using dynamic array define the array 
	
	Find smallest and biggest salary element in a salary dynamic array 
	
	use findSmallest, findBiggest functions

Test Case:
Input:
5
1300.0 1500.0 1250.0 1450.0 1350.0
Ouput:
1250
1500

*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
void read_salaries(float* salaires, int N)
{
    for (int I = 0; I < N; I++) {
        scanf("%f", &salaires[I]); //scanf("%f", *(salaires + I));
    }
}
float findSmallest(float* salaries, int N)
{
    float smallest = salaries[0];
    for (int I = 1; I < N; I++)
    {
        if (salaries[I] < smallest)
        {
            smallest = salaries[I];
        }
    }
    return smallest;
}
float findBiggest(float* salaries, int N)
{
    float biggest = salaries[0];
    for (int I = 1; I < N; I++)
    {
        if (salaries[I] > biggest)
        {
            biggest = salaries[I];
        }
    }
    return biggest;
}
int main()
{
    // float salaries[1000];
    int N;
    scanf("%d", &N);
    float* salaries = (float*)malloc(sizeof(float) * N);
    read_salaries(salaries, N);
    printf("Smallest Salary is %f", findSmallest(salaries, N));
    printf("Biggest Salary is %f", findBiggest(salaries, N));
    free(salaries);
    return 0;
}
