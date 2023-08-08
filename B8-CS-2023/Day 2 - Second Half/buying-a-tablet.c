#include<stdio.h>
void solve()
{
	int N,B;
	scanf("%d%d",&N,&B);
	int LA=0;
	for(int I=1; I<=N;I++){
		int W,H,P;
		scanf("%d%d%d",&W,&H,&P);
		if(P <= B){
			int A = W * H;
			if(A > LA){
				LA = A;
			}
		}
	}
	if(LA){
		printf("%d",LA);
	}else{
		printf("no tablet");
	}
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){solve();}
	return 0;
}