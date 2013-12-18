#include "priorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* create(){
    Queue *queue = calloc(sizeof(Queue),1);
    return queue;
}
int frontEnqueue(Node *process,Queue *queue){
    if(queue->front == NULL)
   	  process->next = NULL;
    else process->next = queue->front;
    queue->front = process;
    queue->length++;
    return 1;        
}
int enqueue(Queue *queue,Node *node,compFunc* compare){
    Node *previous,*next,*temp;
    int result;
    temp = queue->front;
    if(queue->length == 0 || compare(&node->priority,&temp->priority) < 0)                
        return frontEnqueue(node,queue);
    while(temp != NULL){
        previous = temp;
        next = temp->next;
        if(node->priority < next->priority){
            previous->next = node;
            node->next = next;
            printf("%d\n",queue->length);
            return queue->length++;
        }
    };
    return 0;
}
int dequeue(Queue *queue){
    if(queue->length == 0) return 0;
    queue->front = queue->front->next;
    queue->length--;
    return 1;
}