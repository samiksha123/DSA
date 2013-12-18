#include "testUtils.h"
#include "stackll.h"
#include <stdlib.h>
#include <stdio.h>

void test_add_data_to_empty_stack(){
	List* list = create();
	int num = 5;
	int res = push(list, &num);
	ASSERT(1 == res);
}
void test_push_data_to_list(){
	List* list = create();
	int num = 5;
	int num1 = 6;
	int num2 = 6;
	ASSERT(push(list, &num));
	ASSERT(push(list, &num1));
	ASSERT(push(list, &num2));
}
void test_push_float_data_to_list(){
	List* list = create();
	float num = 5.1;
	float num1 = 6.2;
	float num2 = 3.1;
	ASSERT(push(list, &num));
	ASSERT(push(list, &num1));
	ASSERT(push(list, &num2));
}
void test_push_char_data_to_list(){
	List* list = create();
	char num = 'a';
	char num1 = 'b';
	char num2 = 'c';
	ASSERT(push(list, &num));
	ASSERT(push(list, &num1));
	ASSERT(push(list, &num2));
}
void test_delete_last_element_in_list(){
	List* list = create();
	int result;
	int num = 1;
	int num2 = 2;
	ASSERT(push(list, &num));
	ASSERT(push(list, &num2));
	result = *(int*)pop(list);
	ASSERT(2 == result);
}
void test_delete_float_element_in_list(){
	List* list = create();
	float result;
	float num = 1.1f;
	float num2 = 2.2f;
	ASSERT(push(list, &num));
	ASSERT(push(list, &num2));
	result = *(float*)pop(list);
	ASSERT(2.2f == result);
}
void test_delete_char_element_in_list(){
	List* list = create();
	char result;
	char num = 'a';
	char num2 = 'b';
	ASSERT(push(list, &num));
	ASSERT(push(list, &num2));
	result = *(char*)pop(list);
	ASSERT('b' == result);
}
void test_top_element_in_stack(){
	List* list = create();
	int result;
	int num = 7;
	int num2 = 9;
	ASSERT(push(list, &num));
	ASSERT( push(list, &num2));
	result = *(int*)peak(list);
	ASSERT(9 == result);
}
void test_top_char_element_in_stack(){
	List* list = create();
	char result;
	char num = 'a';
	char num2 = 'b';
	ASSERT(push(list, &num));
	ASSERT( push(list, &num2));
	result = *(char*)peak(list);
	ASSERT('b' == result);
}
