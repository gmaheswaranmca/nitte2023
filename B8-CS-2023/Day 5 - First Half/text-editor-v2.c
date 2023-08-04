#include<stdio.h>
#include<string.h>
char stack[10][1000];
int top=-1;
void append(char* doc, char* W){
	strcat(doc,W);
	strcpy(stack[++top],doc); // state in stack 
	//printf("[Editor:%s]\n",doc);
}
void delete(char* doc, int k){
	int len = strlen(doc); //abcde 3
	int pos = len - k;	   // 5 - 3 = 2
	doc[pos] = '\0';
	strcpy(stack[++top],doc); // state in stack 
	//printf("[Editor:%s]\n",doc);
}
void print(char* doc, int k){
	//printf("[%c]\n",doc[k-1]);
	printf("%c",doc[k-1]);
}
void undo(char* doc){
	strcpy(doc,stack[--top]);	
	//printf("[Editor:%s]\n",doc);
}
int main(){
	char doc[1000] = "";
	char W[100]; int k;
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int op_id;
		scanf("%d",&op_id);
		switch(op_id){
			case 1: scanf("%s",W); append(doc,W);break;
			case 2: scanf("%d",&k);delete(doc,k);break;
			case 3: scanf("%d",&k);print(doc,k);break;
			case 4: undo(doc);break;
		}
	}
	return 0;
}