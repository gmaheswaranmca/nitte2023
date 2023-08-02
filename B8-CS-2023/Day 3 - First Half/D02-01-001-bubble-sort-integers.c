/*
optimized bubble sort for integers

5
5 1 4 2 8

*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
#include<cstdlib>
void read(int array[], int N) {
	for (int I = 0; I < N; I++) {
		scanf("%d", &array[I]);
	}
}
void print(int array[], int N) {
	for (int I = 0; I < N; I++) {
		printf("%d ", array[I]);
	}
}
void swap(int* ptrA, int* ptrB) {
	int t = (*ptrA);
	(*ptrA) = (*ptrB);
	(*ptrB) = t;
}
void bubble_sort(int array[], int M) {
	int isSwapped;
	do{
		isSwapped = 0;
		//pass
		for (int I = 0; I < (M - 1); I++) {
			if (array[I] > array[I + 1]) {
				swap(&array[I], &array[I + 1]);
				isSwapped = 1;
			}
		}
		M--;
	} while (isSwapped);
}
int main(){
	int array[SIZE];
	int N;
	scanf("%d", &N);
	read(array, N);
	print(array, N); printf("\n");
	bubble_sort(array, N);
	print(array, N); printf("\n");
	return 0;
}

