typedef int comparator(void* , void*);
typedef char String[256];
int merge(void** base, void** left, void** right, int leftLength, int rightLength, comparator cmp);
void mergeSort(void** base, int numberOfElements,comparator comp);


