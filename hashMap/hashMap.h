#include "../linked_list/dlinkList.h"
typedef char String[256];
typedef	int (*HashCodeGenerator)(void* key,int capacity);
typedef int (*Compare)(void* element1,void* element2);
typedef struct{
	Compare compare;
	HashCodeGenerator hashCode;
	void* buckets;
	int capacity;
}HashMap;

typedef struct{
	void* key;
	void* value;
}Data;

HashMap* createHashMap(HashCodeGenerator hashCode,Compare compare);
int put(HashMap* hm,void* key,void* value);
void* get(HashMap* hm,void* key);
void* removeData(HashMap* hm,void* key);
void dispose(HashMap* hm);
Data* getData(void* key,void* data);

