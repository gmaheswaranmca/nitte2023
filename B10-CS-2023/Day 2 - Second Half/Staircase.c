#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	
	char spaces[] = "                                              ";
	char stars[] = "***********************************************";
	
	//printf("%.5s\n",stars);
	//printf("%.*s",7,stars);
	for(int I = 1; I <= N; I++)
		printf("%.*s%.*s\n",(N-I),spaces,I,stars);
	
	return 0;
}