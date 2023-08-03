/*

*/
#include<stdio.h>
void solve(){
	int N,M,K;//sources#,ignored#,tracked#
	scanf("%d%d%d",&N,&M,&K);
	int Flag[1000] = {};
	for(int I=0; I<M; I++){
		int inum;
		scanf("%d",&inum);
		Flag[inum-1]++;
	}
	for(int I=0; I<K; I++){
		int tnum;
		scanf("%d",&tnum);
		Flag[tnum-1]++;
	}
	int c1=0,c2=0;
	for(int I=0; I<N; I++){
		if(Flag[I]==2){
			c1++;
		}else if(Flag[I]==0){
			c2++;
		}
	}
	printf("%d %d",c1,c2);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){solve();}
	return 0;
}