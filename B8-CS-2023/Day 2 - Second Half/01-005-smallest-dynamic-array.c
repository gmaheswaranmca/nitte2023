#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
#include<cstdlib>
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
	//float salaries[SIZE];
	
	int N;
	scanf("%d", &N);
	float* salaries = (float*)malloc(sizeof(float)*N);
	read_salaries(salaries, N);
	printf("%f", findSmallest(salaries, N));
	free(salaries);
	return 0;
}

