typedef char String[50];
typedef int compare(void* , void*);
void* binarySearch(void* base,void* key,int num,int size,compare* compare);