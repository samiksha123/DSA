#include "testUtils.h"
#include "inSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>


int compareInt(void* first,void* second){
	return *(int*)first - *(int*)second;
}

int compareFloat(void* first,void* second){
	return *(float*)first - *(float*)second;
}

int compareChar(void* first,void* second){
	return *(char*)first - *(char*)second;
}

void test_sort_integer_data(){
	int data[5] = {5,2,8,1,3};
	int expected[5] = {1,2,3,5,8};
	isort(data, 5, sizeof(int), compareInt);
	ASSERT(0 == memcmp(data,expected,sizeof(expected)));
}

void test_sort_float_data(){
	float data[5] = {5.2f,2.1f,8.4f,7.7f,8.2f};
	float expected[5] = {2.1f,5.2f,7.7f,8.2f,8.4f};
	isort(data, 5, sizeof(float), compareFloat);
	ASSERT(0 == memcmp(data,expected,sizeof(expected)));
}
void test_sort_character_data(){
	char data[5] = {'d','b','c','a','e'};
	char expected[5] = {'a','b','c','d','e'};
	isort(data, 5, sizeof(char), compareChar);
	ASSERT(0 == memcmp(data,expected,sizeof(expected)));
}