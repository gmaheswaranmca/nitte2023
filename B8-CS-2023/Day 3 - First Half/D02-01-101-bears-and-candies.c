#include <stdio.h>

int main ()
{
  int A,B;
  scanf("%d%d",&A,&B);
  int Li=0,Bo=0;
  int c=1;
  while(Li<=A && Bo<=B){
	if(c %2 == 1){
		Li+=c;
	}else{
		Bo+=c;
	}
	c++;
  }
  if(Li<=A){
	  printf("Limak is won");
  }
  if(Bo <= B){
	  printf("Bob is won");
  }
  return 0;
}
