/*
Optimized bubble sort for integers

5
MOUNIYAA ADHITHYA ANANYA DARSHAN CHRYSTAL

strcmp(a,b)

	hi hello		+ve			>
	hello hi 		-ve 		<
	hello hello 	0

*/

#define SIZE 1000
#include<stdio.h>
#include<string.h>
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
void swap(char* a, char* b) {
	char t[50];
	strcpy(t,a);
	strcpy(a,b);
	strcpy(b,t);
}
void bubble_sort(char array[][50], int M) {
	int isSwapped;
	do{
		isSwapped = 0;
		//pass
		for (int I = 0; I < (M - 1); I++) {
			if (strcmp(array[I],array[I + 1])>0) {
				//(array[I] > array[I + 1]) {
				swap(array[I], array[I + 1]);
				isSwapped = 1;
			}
		}
		M--;
	} while (isSwapped);
}
int main(){
	char array[SIZE][50];
	int N;
	scanf("%d", &N);
	read(array, N);
	print(array, N); printf("\n");
	bubble_sort(array, N);
	print(array, N); printf("\n");
	return 0;
}

