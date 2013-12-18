#include "testUtils.h"
#include "linearQueue.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Queue *queue;
void tearDown(){
	dispose(queue);
}
void test_1_create_queue_for_length_of_given_size(){
	int i;
	int zeroes[]={0,0,0};
	queue = create(sizeof(int),3);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}
void test_create_queue_for_characters(){
	int i;
	char zeroes[]={0,0,0};
	queue = create(sizeof(char),3);
	ASSERT(queue->typeSize==1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_2_create_queue_for_float_elements(){
	float i;
	float zeroes[]={0.0,0.0,0.0};
	queue = create(sizeof(float),3);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_for_insert_int_element_at_front_of_queue(){
	int c=5,res;
	queue = create(sizeof(int),5);
	res = enqueue(queue,&c);
	ASSERT(*(int*)queue->elements == 5);
	ASSERT(res==1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_for_insert_float_element_at_front_of_queue(){
	float c=5.0,res;
	queue = create(sizeof(float),5);
	res = enqueue(queue,&c);
	ASSERT(*(float*)queue->elements == 5.0);
	ASSERT(res==1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}
void test_for_insert_character_at_front_of_queue(){
	char c='a',res;
	queue = create(sizeof(char),5);
	res = enqueue(queue,&c);
	ASSERT(*(char*)queue->elements == 'a');
	ASSERT(res==1);
	ASSERT(queue->typeSize==1);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}
void test_for_insert_string_at_front_of_queue(){
	string s;
	int res;
	strcpy(s,"samiksha");
	queue = create(sizeof(string),5);
	res = enqueue(queue,&s);
	ASSERT(0 == strcmp(*(string*)queue->elements,"samiksha"));
	ASSERT(res==1);
	ASSERT(queue->typeSize==256);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}
void test_for_delete_element_from_front_of_queue(){
	int c = 5,d = 6,res;
	queue = create(sizeof(int),2);
	enqueue(queue, &c);
	enqueue(queue,&d);
	res = *(int*)dequeue(queue);
	ASSERT(5==res);
	ASSERT(0==queue->rear);
}
void test_for_delete_float_element_from_front_of_queue(){
	float c = 5.0,d = 6.0,res;
	queue = create(sizeof(float),2);
	enqueue(queue,&c);
	enqueue(queue,&d);
	res = *(float*)dequeue(queue);
	ASSERT(5.0==res);
	ASSERT(0==queue->rear);
}
void test_for_delete_character_from_front_of_queue(){
	char c = 'a',d = 'b',res;
	queue = create(sizeof(char),2);
	enqueue(queue,&c);
	enqueue(queue,&d);
	res = *(char*)dequeue(queue);
	ASSERT('a'==res);
	ASSERT(0==queue->rear);
}
void test_for_delete_string_from_front_of_queue(){
	string s,s1,res;
	strcpy(s,"samiksha");
	strcpy(s1,"kavita");
	queue = create(sizeof(string),2);
	enqueue(queue,&s);
	enqueue(queue,&s1);
	strcpy(res,*(string*)dequeue(queue));
	ASSERT(0==strcmp(res,"samiksha"));
	ASSERT(0==queue->rear);
}
