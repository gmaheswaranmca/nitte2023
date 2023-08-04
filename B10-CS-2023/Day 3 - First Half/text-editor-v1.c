#include<stdio.h>
#include<string.h>
void print(char* doc, int pos){
	printf("[%c]\n",doc[pos-1]);
}
void append(char* doc, char* str){
	strcat(doc,str);
	printf("[Editor:%s]\n",doc);
}
void delete(char* doc, int k){
	int len = strlen(doc);
	int pos = len - k;
	doc[pos] = '\0';
	printf("[Editor:%s]\n",doc);
}
int main()
{
	char doc[1000] = "abcde";
	append(doc,"fg");
	print(doc,6);
	delete(doc,5);
	return 0;
}