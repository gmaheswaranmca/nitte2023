/* Implement Stack using Singly LL 

   front = {10 -> 20 -> 30 -> 40 [x]}
   
   push
   pop

				front = {10 -> 20 -> 30 -> 40 [x]}
		push 70 front = {70 -> 10 -> 20 -> 30 -> 40[x]}
		pop     front =  {10 -> 20 -> 30 -> 40[x]}          70
*/

#include<stdio.h>
#include<stdlib.h>
struct _node_t{
	float data;
	struct _node_t* next;
};
typedef struct _node_t node_t;

node_t* new_node(float data){
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;
	return node;
}

struct _stack_t{
	node_t* front;
};
typedef struct _stack_t stack_t;

void push(float data, stack_t* ptr_stack){
	node_t* node = new_node(data);
	node->next = ptr_stack->front;
	ptr_stack->front = node;
}

float pop(stack_t* ptr_stack){
	node_t* node = ptr_stack->front;
	if(node == NULL){
		printf("Stack is empty.");
		return 0;
	}
	ptr_stack->front = node->next;
	return node->data;
}


int main(){
	stack_t stack;
	stack.front = NULL;
	
	push(10,&stack);
	push(20,&stack);
	push(30,&stack);
	printf("%f\n",pop(&stack));
	printf("%f\n",pop(&stack));
	return 0;
}
