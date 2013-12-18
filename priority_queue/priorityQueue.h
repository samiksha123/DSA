typedef char string[256];
typedef struct queue{
    void* data;
    int priority;
    struct queue *next;
}Node;
typedef struct{
    Node *front;
    int length;
}Queue;
Queue* create();
typedef int compFunc(void* , void*);
int enqueue(Queue *queue,Node *node,compFunc* compare);
int dequeue(Queue* queue);
