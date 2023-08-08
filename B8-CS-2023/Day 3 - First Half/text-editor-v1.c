/* text - editor

*/
#include<stdio.h>
#include<string.h>

void append(char* doc, char* W){
	strcat(doc,W);
	printf("[Editor:%s]\n",doc);
}
void delete(char* doc, int k){
	int len = strlen(doc); //abcde 3
	int pos = len - k;	   // 5 - 3 = 2
	doc[pos] = '\0';
	printf("[Editor:%s]\n",doc);
}
void print(char* doc, int k){
	printf("[%c]\n",doc[k-1]);
}
int main(){
	char doc[1000] = "abcde";
	append(doc,"fg");
	print(doc,6);
	delete(doc,5);
	return 0;
}