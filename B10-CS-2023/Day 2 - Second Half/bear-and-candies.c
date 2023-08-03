#include<stdio.h>
int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	int Li=0,Bo=0;
	int E = 1;
	while(Li <= A && Bo <= B){
		if(E % 2 == 1){
			Li += E;
		}else{
			Bo += E;
		}
		E++;
	}
	if(Li <= A){
		printf("Limak");
	}
	else{
		printf("Bob");
	}
	return 0;
}
/*
for(int I=1; Li <= A && Bo <= B ;I++){
		if(I % 2 == 1){
			Li += I;
		}else{
			Bo += I;
		}
	}
*/	