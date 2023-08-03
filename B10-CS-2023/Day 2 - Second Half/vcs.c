#include<stdio.h>
#define SIZE 1000
int main()
{
	int N,M,K;
	int IG[SIZE];
	int TR[SIZE];
	scanf("%d%d%d",&N,&M,&K);
	for(int I=0; I<M; I++){
		scanf("%d",&IG[I]);
	}
	for(int I=0; I<K; I++){
		scanf("%d",&TR[I]);
	}
	int IIG=0,ITR=0;
	int C1=0;
	while(IIG<M && ITR<K){
		if(IG[IIG]==TR[ITR]){
			C1++;
			IIG++;
			ITR++;			
		}else if(IG[IIG] > TR[ITR]){
			ITR++;
		}else{
			IIG++;
		}
	}
	printf("%d",C1);
	return 0;
}