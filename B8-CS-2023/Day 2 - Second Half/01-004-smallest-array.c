/*
Input
5
1800 1500 1300 3000 1700
Ouput
1300
*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
void read_salaries(float salaries[], int N){
//void read_salaries(float* salaries, int N)
	for (int I = 0; I < N; I++)	{
		scanf("%f", &salaries[I]);
	}
}
float findSmallest(float salaries[], int N) {
	float small = salaries[0];
	for (int I = 1; I < N; I++) {
		if (salaries[I] < small) {
			small = salaries[I];
		}
	}
	return small;
}
int main(){
	float salaries[SIZE];
	int N;
	scanf("%d", &N);
	read_salaries(salaries, N);
	printf("%f", findSmallest(salaries, N));
	return 0;
}

