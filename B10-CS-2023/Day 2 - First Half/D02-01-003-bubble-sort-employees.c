/*
bubble sort for emp{name, salary}
sort by salary 
5
SAMEER 3400 RAKSHA 2800 NAVYA 2200 SHARAN 4300 ROHIT 3800
*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
struct _emp_t
{
	char name[50];
	float salary;
};
typedef struct _emp_t emp_t;
void swap(emp_t* ptrA, emp_t* ptrB)
{
	emp_t t = (*ptrA);
	(*ptrA) = (*ptrB);
	(*ptrB) = t;
}
void read(emp_t* array, int N) {
	for (int I = 0; I < N; I++) {
		scanf("%s%f", array[I].name, &array[I].salary);
	}
}
void print(emp_t* array, int N) {
	for (int I = 0; I < N; I++) {
		printf("[%s %.2f] ", array[I].name, array[I].salary);
	}
}
void bubble_sort(emp_t* array, int M)
{
	int isSwapped = 0;
	do {
		isSwapped = 0;
		for (int I = 0; I < (M - 1); I++)
		{
			if (array[I].salary > array[I + 1].salary) {
				swap(&array[I], &array[I + 1]);
				isSwapped = 1;
			}
		}
		M--;
	} while (isSwapped);
}

int main() {
	emp_t array[SIZE];
	int N;
	scanf("%d", &N);
	read(array, N);
	print(array, N); printf("\n");
	bubble_sort(array, N);
	print(array, N); printf("\n");
	return 0;
}
 
