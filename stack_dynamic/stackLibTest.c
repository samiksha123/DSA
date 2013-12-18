#include "testUtils.h"
#include "stackLib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void test_1_create_stack_for_length_of_given_size(){
	int i;
	Stack* stack;
	int zeroes[]={0,0,0,0,0};
	stack = create(sizeof(int),3);
	ASSERT(stack->typeSize==4);
	ASSERT(stack->top==-1);
	ASSERT(stack->length==3);
	free(stack);
}
void test_2_create_stack_for_float(){
	float i;
	Stack* stack;
	float zeroes[]={0,0,0,0,0};
	stack = create(sizeof(float),3);
	ASSERT(stack->typeSize==4);
	ASSERT(stack->top==-1);
	ASSERT(stack->length==3);
	free(stack);
}
void test_3_create_stack_for_char(){
	char i;
	Stack* stack;
	char zeroes[]={0,0,0,0,0};
	stack = create(sizeof(char),3);
	ASSERT(stack->typeSize==1);
	ASSERT(stack->top==-1);
	ASSERT(stack->length==3);
	free(stack);
}
void test_4_push_int_element_at_top_of_stack(){
	int i;
	Stack* stack;
	int c=5,res;
	stack = create(sizeof(int),5);
	res = push(stack,&c);
	ASSERT(res==1);
	dispose(stack);
}

void test_5_push_float_element_at_top_of_stack(){
	float i;
	Stack* stack;
	float c=5.0f;
	int res;
	stack = create(sizeof(float),5);
	res = push(stack,&c);
	ASSERT(res == 1);
	dispose(stack);
}
void test_7_pop_int_element_at_top_of_stack(){
	int i , element;
	Stack* stack;
	int n = 3,n1 = 2,n2 = 4;
	stack = create(sizeof(int),3);
	ASSERT(push(stack,&n));
	ASSERT(push(stack,&n1));
	ASSERT(push(stack,&n2));
	element = *(int*)pop(stack);
	ASSERT(element == 4);
	dispose(stack);
}
void test_8_pop_float_element_at_top_of_stack(){
	float i , element;
	Stack* stack;
	float n = 1.0f,n1 = 2.0f,n2 = 3.0f;
	stack = create(sizeof(float),3);
	ASSERT(push(stack,&n));
	ASSERT(push(stack,&n1));
	ASSERT(push(stack,&n2));
	element = *(float*)pop(stack);
	ASSERT(element == 3.0f);
	dispose(stack);
}

void test_9_pop_float_element_at_top_of_stack(){
	char i , element;
	Stack* stack;
	char n = 'a',n1 = 'b',n2 = 'c';
	stack = create(sizeof(char),3);
	ASSERT(push(stack,&n));
	ASSERT(push(stack,&n1));
	ASSERT(push(stack,&n2));
	element = *(char*)pop(stack);
	ASSERT(element == 'c');
	ASSERT(push(stack,&n));
	element = *(char*)pop(stack);
	ASSERT(element == 'a');
	dispose(stack);
}

void test_10_should_give_top_element(){
	int element;
	Stack* stack;
	int c=5,d=7;
	stack = create(sizeof(int),2);
	push(stack,&c);
	push(stack,&c);
	push(stack,&d);
	ASSERT(7 == *(int*)top(stack));
	pop(stack);
	ASSERT(5 == *(int*)top(stack));
	dispose(stack);
}

void test_10_should_give_top_float_element(){
	Stack* stack;
	float c=5.4f,d=7.3f;
	stack = create(sizeof(float),2);
	push(stack,&c);
	push(stack,&c);
	push(stack,&d);
	ASSERT(7.3f == *(float*)top(stack));
	pop(stack);
	ASSERT(5.4f == *(float*)top(stack));
	dispose(stack);
}

void test_11_if_stack_is_full(){
	Stack* stack;
	int c = 5,res;
	stack = create(sizeof(char),2);
	push(stack,&c);
    push(stack,&c);
	push(stack,&c);
	res = isFull(stack);
	ASSERT(res == 1);
	dispose(stack);
}
void test_12_if_stack_is_empty(){
	Stack* stack;
	int c = 5,res;
	stack = create(sizeof(char),2);
	res = isEmpty(stack);
	ASSERT(res == 1);
	dispose(stack);
}