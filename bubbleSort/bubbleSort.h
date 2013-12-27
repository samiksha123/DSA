typedef int (*compare)(void* element1,void* element2);
void bubbleSort(void* data,int noOfElements,int elementSize,compare comp);