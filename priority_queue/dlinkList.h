#include <stdbool.h>
typedef struct node{
	struct node* previous;
	void* data;
	struct node* next;
}Node;

typedef struct{
	Node* head;
	int length;
}List;


List* create();
Node* createNode(void* previous,void* next);
int insert(List* list,int index,void * element);
void get(Node* list, int index);
void* deleteNode(List* list, int index);
