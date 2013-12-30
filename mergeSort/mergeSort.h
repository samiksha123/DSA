typedef int comparator(void* , void*);

//void part(void* base,int min,int max,compare* compare,int elementSize);
//void merge(void* base,int min,int mid,int max,compare* compare,int elementSize);

int merge(void** base, void** left, void** right, int leftLength, int rightLength, comparator cmp);
void mergeSort(void** base, int numberOfElements,comparator comp);


