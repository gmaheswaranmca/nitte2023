#include<stdio.h>
#include<string.h>
int main(){
int i = 0;
char str[32] = "Polali Raajaraajeshwari";
for(; str[i] != 0; ++i);
printf("%d", i);
}