/*
optimized bubble sort for names

strcmp(first,second)
	0      for ==
	-ve    for < 
	+ve    for >
	
	hi hello      +ve  > 
	hello hi      -ve  < 
	hello hello   0
	
	
5
SAMEER RAKSHA NAVYA SHARAN ROHIT 

NAVYA RAKSHA ROHIT SAMEER SHARAN
*/


#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
#include<cstring>
void swap(char ptrA[], char ptrB[])
{
	char t[50];
	strcpy(t,ptrA);
	strcpy(ptrA, ptrB);
	strcpy(ptrB, t);
}
void read(char array[][50], int N) {
	for (int I = 0; I < N; I++) {
		scanf("%s", array[I]);
	}
}
void print(char array[][50], int N) {
	for (int I = 0; I < N; I++) {
		printf("%s ", array[I]);
	}
}
void bubble_sort(char array[][50], int M)
{
	int isSwapped = 0;
	do {
		isSwapped = 0;
		for (int I = 0; I < (M - 1); I++)
		{
			if (strcmp(array[I], array[I + 1]) > 0) { //array[I] > array[I + 1]
				swap(array[I], array[I + 1]);
				isSwapped = 1;
			}
		}
		M--;
	} while (isSwapped);
}

int main() {
	char array[SIZE][50];
	int N;
	scanf("%d", &N);
	read(array, N);
	print(array, N); printf("\n");
	bubble_sort(array, N);
	print(array, N); printf("\n");
	return 0;
}
