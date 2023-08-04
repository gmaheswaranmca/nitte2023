/*
	realloc
		case 1
		allocated size 10
		increasing towards 15 blocks
		????
			buffer the 10 blocks data 
			free old 10 blocks 
			alloc 15 blocks 
			copy back 10 blokcs data here to new blocks 
		case 2
			10 blocks to 5 blocks
			....
			buffer the 5 blocks data 
			free old 10 blocks 
			alloc 5 blocks 
			copy back 5 blokcs data here to new blocks 
	
	stack using singly LL
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int main(){
	//[1,{3|}]->[2,{|cdefg}]->[1,{6|}]
	stack_t stack;
	stack.front = NULL; //to avoid wild ptr 
	//[1,{6|}]
	op_t op; op.op_id = 1; op.op_data.pos = 6;
	push(&stack, op);
	op_t op2; op2.op_id = 2; strcpy(op2.op_data.str, "cdefg");
	push(&stack, op2);
	op_t op3; op3.op_id = 1; op3.op_data.pos = 3;
	push(&stack, op3);
	
	op_t pop_op = pop(&stack); //1st pop 
	if(pop_op.op_id == 1){
		printf("[%d,%d]",pop_op.op_id,pop_op.op_data.pos);
	}else{
		printf("[%d,%s]",pop_op.op_id,pop_op.op_data.str);
	}
	pop_op = pop(&stack); //2nd pop 
	if(pop_op.op_id == 1){
		printf("[%d,%d]",pop_op.op_id,pop_op.op_data.pos);
	}else{
		printf("[%d,%s]",pop_op.op_id,pop_op.op_data.str);
	}
	
	return 0;
}




















	


