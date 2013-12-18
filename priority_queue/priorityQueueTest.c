#include "testUtils.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
Queue *queue;
void test_for_create_a_new_queue(){
    Queue expected = {NULL,0};
    queue = create();
    ASSERT(queue->front == expected.front);
    ASSERT(queue->length == expected.length);
}
void test_for_adding_integer_element(){
    int value[] = {10,20};
    Queue expected = {NULL,0};
    Node firstNode = {&value,30,NULL};
    Node secondNode = {&value,20,NULL};
    queue = create();
    ASSERT(1 == enqueue(queue, &firstNode,compareInt));
    ASSERT(1 == enqueue(queue, &secondNode,compareInt));
}
void test_for_adding_char_element(){
 float value[] = {20.0f,10.0f};
    Node firstNode = {&value[0],3,NULL};
    Node secondNode = {&value[1],2,NULL};
    queue = create();
    ASSERT(1 == enqueue(queue, &firstNode,compareInt));
    ASSERT(1 == enqueue(queue, &secondNode,compareInt));
}

void test_for_adding_string_element(){
    string value[] = {"samiksha","manali"};
    Node firstNode = {&value[0],3,NULL};
    Node secondNode = {&value[1],2,NULL};
    queue = create();
    ASSERT(1 == enqueue(queue, &firstNode,compareInt));
    ASSERT(1 == enqueue(queue, &secondNode,compareInt));
}
void test_for_remove_integer_element_from_queue(){
    int value[] = {1,2,3};
    Node *second,*third;
    Node firstNode = {&value[0],4,NULL};
    Node secondNode = {&value[1],3,NULL};
    Node thirdNode = {&value[2],2,NULL};
    queue = create();
    ASSERT(1 == enqueue(queue, &firstNode,compareInt));
    ASSERT(1 == enqueue(queue, &secondNode,compareInt));
    ASSERT(1 == enqueue(queue, &thirdNode,compareInt));
    second = queue->front->next;
    third = second->next;
    ASSERT(1 == dequeue(queue));
    ASSERT(1 == dequeue(queue));
    ASSERT(1 == dequeue(queue));
}

void test_for_remove_float_element_from_queue(){
    float value[] = {1.1,2.2,3.3};
    Node *second,*third;
    Node firstNode = {&value[0],4,NULL};
    Node secondNode = {&value[1],3,NULL};
    Node thirdNode = {&value[2],2,NULL};
    queue = create();
    ASSERT(1 == enqueue(queue, &firstNode,compareInt));
    ASSERT(1 == enqueue(queue, &secondNode,compareInt));
    ASSERT(1 == enqueue(queue, &thirdNode,compareInt));
    second = queue->front->next;
    third = second->next;
    ASSERT(1 == dequeue(queue));
    ASSERT(1 == dequeue(queue));
    ASSERT(1 == dequeue(queue));
    ASSERT(0 == dequeue(queue));
}

void test_for_remove_character_from_queue(){
    char value[] = {'a','b','c'};
    Node *second,*third;
    Node firstNode = {&value[0],4,NULL};
    Node secondNode = {&value[1],3,NULL};
    Node thirdNode = {&value[2],2,NULL};
    queue = create();
    ASSERT(1 == enqueue(queue, &firstNode,compareInt));
    ASSERT(1 == enqueue(queue, &secondNode,compareInt));
    ASSERT(1 == enqueue(queue, &thirdNode,compareInt));
    second = queue->front->next;
    third = second->next;
    ASSERT(1 == dequeue(queue));
    ASSERT(1 == dequeue(queue));
    ASSERT(1 == dequeue(queue));
    ASSERT(0 == dequeue(queue));
}

