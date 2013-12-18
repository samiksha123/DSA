#include "linearQueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Queue* create(int typeSize, int length){
	Queue* queue = (Queue*)calloc(1,sizeof(Queue));
	queue->rear=-1;
	queue->elements= calloc(length,typeSize);
	queue->length=length;
	queue->typeSize=typeSize;
	return queue;
}
int isFull(Queue* queue){
	if(queue->rear == queue->length-1)
		return 1;
	return 0;
}
bool enqueue(Queue* queue,void* element){
	if(isFull(queue)) return false;
	queue->rear++;
	if(memcpy((queue->elements+(queue->typeSize*queue->rear)) , element,queue->typeSize))
		return true;
	return false;
}
int isEmpty(Queue* queue){
	if(queue->rear == -1)
		return 1;
	return 0;
}
void* dequeue(Queue* queue){
	void* element = malloc(queue->typeSize);
	memcpy(element,queue->elements,queue->typeSize);
	if(isEmpty(queue)) return 0;
	memmove( queue->elements,queue->elements+queue->typeSize,queue->length-1);
	queue->rear--;
	return element;
}
void dispose(Queue* queue){
	free(queue);
}