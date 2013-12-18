#include "stackmem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Stack* create(int typeSize, int length){
	Stack* stack = (Stack*)calloc(1,sizeof(Stack));
	stack->top=-1;
	stack->elements= calloc(length,typeSize);
	stack->length=length;
	stack->typeSize=typeSize;
	return stack;
}
bool push(Stack* stack,void* element){
	if(isFull(stack)) return false;
		stack->top++;
		memcpy((stack->elements+(stack->typeSize*stack->top)) , element,stack->typeSize);
	return true;
}
void* pop(Stack* stack){
	void* element = malloc(stack->length*stack->typeSize);
	if(isEmpty(stack)) return false;
	element = stack->elements+(stack->typeSize*stack->top--);
	return element;
}
void* top(Stack* stack){
	void* element;
	element = stack->elements+(stack->typeSize*stack->top);
	return element;
}
int isFull(Stack* stack){
	return (stack->top == stack->length);
}
int isEmpty(Stack* stack){
	return (stack->top == -1);
}
void dispose(Stack* stack){
	free(stack);
}