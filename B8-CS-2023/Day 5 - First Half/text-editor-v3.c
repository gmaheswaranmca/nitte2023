#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//stack 
union _op_data_t{
	int pos;
	char str[255];
};

typedef union _op_data_t op_data_t;

struct _op_t{
	int op_id;
	op_data_t op_data;
};

typedef struct _op_t op_t;

struct _node_t{
	op_t op;
	struct _node_t *next;	
};
typedef struct _node_t node_t;

node_t* new_node(op_t op){
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->op = op;
	node->next = NULL;
	return node;
}

struct _stack_t{
	node_t* front;
};
typedef struct _stack_t stack_t;
// 			front 		[]->[1,{6|}]->[2,{|cdefg}][x]
//		push [1,{3|}]   [] -> [1,{3|}]->[1,{6|}]->[2,{|cdefg}][x]		
//      pop             [] -> [1,{6|}]->[2,{|cdefg}][x]					
//								[1,{3|}]
void push(stack_t* stack, op_t op){
	node_t* node = new_node(op);
	node->next = stack->front;
	stack->front = node;
}

int is_empty(stack_t* stack){
	if(stack->front == NULL){
		return 1;
	}
	return 0;
}

op_t pop(stack_t* stack){
	node_t* node = stack->front;
	stack->front = node->next;
	return node->op; 
}



//text editor v1 
struct _editor_t{
	char doc[1000];
	stack_t stack;
};
typedef struct _editor_t editor_t;
void print(editor_t* editor, int pos){
	printf("[%c]\n",editor->doc[pos-1]);
}
void append(editor_t* editor, char* str){
	int pos = strlen(editor->doc) + 1;
	strcat(editor->doc,str);
	//state [op_id,pos|str]
	op_t op; op.op_id = 1; op.op_data.pos = pos;
	push(&editor->stack, op);
	//end state 
	printf("[Editor:%s]\n",editor->doc);
}
void delete(editor_t* editor, int k){
	int len = strlen(editor->doc);
	int pos = len - k;
	char str[255];
	strcpy(str,editor->doc + pos);
	//delete 
	editor->doc[pos] = '\0';
	//state [op_id,pos|str]
	op_t op; op.op_id = 2; strcpy(op.op_data.str,str);
	push(&editor->stack, op);
	//end state 
	printf("[Editor:%s]\n",editor->doc);
}
void undo(editor_t* editor){
	if(is_empty(&editor->stack)){
		printf("[Cannot be undone.]\n");
		return;
	}
	op_t op = pop(&editor->stack);
	if(op.op_id == 1){
		editor->doc[op.op_data.pos-1] = '\0';
	}else if(op.op_id == 2){
		strcat(editor->doc, op.op_data.str);
	}
	printf("[Editor:%s]\n",editor->doc);
}
int main()
{
	editor_t editor; 
	strcpy(editor.doc,"abcde"); 
	append(&editor,"fg"); //0
	print(&editor,6);  //1
	delete(&editor,5); //2
	undo(&editor);	   //3 	
	print(&editor,7);  //4
	undo(&editor);	   //5
	print(&editor,4);  //6
	return 0;
}