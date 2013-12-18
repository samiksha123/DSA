#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>

Queue* queue;
void teardown(){
	dispose(queue);
}
int isFull(Queue* queue);
int isEmpty(Queue* queue);

void test_1_create_queue_for_length_of_given_size(){
	int i;
	int zeroes[]={0,0,0};
	queue = create(sizeof(int),3);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->front==-1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}
void test_2_create_queue_for_float_elements(){
	float i;
	float zeroes[]={0.0,0.0,0.0};
	queue = create(sizeof(float),3);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->front==-1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}
void test_for_insert_int_element_at_front_of_queue(){
	int i;
	int c=5,res;
	queue = create(sizeof(int),5);
	res = enqueue(queue,&c);
	ASSERT(*(int*)queue->elements == 5);
	ASSERT(res==1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}
void test_for_insert_char_element_at_front_of_queue(){
	char c='a',c1 = 'b',c2 = 'c',res;
	queue = create(sizeof(char),3);
	ASSERT(enqueue(queue,&c));
	ASSERT(enqueue(queue,&c1));
	ASSERT(enqueue(queue,&c2));
	res = *(char*)dequeue(queue);
	ASSERT(res=='a');
}
void test_for_insert_string_element_at_front_of_queue(){
	string c;
	int res;
	strcpy(c,"samiksha");
	queue = create(sizeof(string),5);
	res = enqueue(queue,&c);
	ASSERT(0==strcmp(*(string*)queue->elements,"samiksha"));
	ASSERT(res==1);
}

void test_for_delete_int_element_at_front_of_queue(){
	int i , element;
	int n =4,n1 = 3,n2 = 4;
	queue = create(sizeof(int),3);
	enqueue(queue,&n);
	enqueue(queue,&n1);
	enqueue(queue,&n2);
	element = *(int*)dequeue(queue);
	ASSERT(element == 4);
}
void test_for_delete_float_element_at_front_of_queue(){
	float element;
	float n = 1.1f,n1 = 2.1f,n2 = 3.2f;
	queue = create(sizeof(float),5);
	enqueue(queue,&n);
	enqueue(queue,&n1);
	enqueue(queue,&n2);
	element = *(float*)dequeue(queue);
	ASSERT(element == 1.1f);
}
void test_for_delete_char_element_at_front_of_queue(){
	char element;
	char n = 'a',n1 ='b',n2 = 'c';
	queue = create(sizeof(char),3);
	enqueue(queue,&n);
	enqueue(queue,&n1);
	enqueue(queue,&n2);
	element = *(char*)dequeue(queue);
	ASSERT(element == 'a');
}

void test_if_queue_is_full(){
	int c = 5,res;
	queue = create(sizeof(char),2);
	enqueue(queue,&c);
    enqueue(queue,&c);
	enqueue(queue,&c);
	ASSERT(isFull(queue));
}
void test_if_queue_is_empty(){
	int c = 5,res;
	queue = create(sizeof(char),2);
	ASSERT(isEmpty(queue));
}
