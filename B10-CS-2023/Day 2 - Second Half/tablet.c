#include<stdio.h>
int main()
{
	int n,b;
	scanf("%d%d",&n,&b);
	int la=0;
	for(int I=1; I <= n; I++){
		int w,h,p;
		scanf("%d%d%d",&w,&h,&p);
		if(p <= b){
			int a = w * h;
			if(a > la){
				la = a;
			}
		}
	}
	if(la){
		printf("%d",la);
	}else{
		printf("no tablet");
	}
	return 0;
}