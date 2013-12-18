#include <stdbool.h>
typedef char string[256];

typedef struct{
	void* elements;
	int typeSize;
	int top;
	int length;
}Stack;

Stack* create(int,int);
bool push(Stack* stack,void* element);
void* pop(Stack* stack);
int isFull(Stack* stack);
int isEmpty(Stack* stack);

void* top(Stack* stack);

void copy(void *str1,void *str2, int size);

void dispose(Stack* stack);
