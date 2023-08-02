/*
  optimized bubble sort for integers
  M = N
let a = array of N items[5 1 4 2 8]
do  
	isSwapped = false 
	for I = 0 .. M-2
		if a[I] > a[I+1]:
			swap(a[I],a[I+1])
			isSwapped = true 
		end if 
	end for 
	M--
while isSwapped
*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
void swap(int* ptrA, int* ptrB)
{
	int t = (*ptrA);
	(*ptrA) = (*ptrB);
	(*ptrB) = t;
}
void read(int* array, int N) {
	for (int I = 0; I < N; I++) {
		scanf("%d", &array[I]);
	}
}
void print(int* array, int N) {
	for (int I = 0; I < N; I++) {
		printf("%d ", array[I]);
	}
}
void bubble_sort(int* array, int M)
{
	int isSwapped = 0;
	do {
		isSwapped = 0;
		for (int I = 0; I < (M - 1); I++)
		{
			if (array[I] > array[I + 1]) {
				swap(&array[I], &array[I + 1]);
				isSwapped = 1;
			}
		}
		M--;
	} while (isSwapped);
}

int main() {
	int array[SIZE];
	int N;
	scanf("%d", &N);
	read(array, N);
	print(array, N); printf("\n");
	bubble_sort(array, N);
	print(array, N); printf("\n");
	return 0;
}
