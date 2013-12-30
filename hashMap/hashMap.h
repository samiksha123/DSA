#include "../linked_list/dlinkList.h"
typedef char String[256];
typedef	int (*HashCodeGenerator)(void* key);
typedef int (*Compare)(void* element1,void* element2);
typedef struct{
	Compare compare;
	HashCodeGenerator hashCode;
	void** buckets;
	int capacity;
}HashMap;

typedef struct{
	void* key;
	void* value;
}HashElement;

HashMap* createHashMap(HashCodeGenerator hashCode,Compare compare);
int put(HashMap* hm,void* key,void* value);
void* get(HashMap* hm,void* key);
int removeData(HashMap* hm,void* key);
Iterator keys(HashMap* hm);
void dispose(HashMap* hm);
HashElement* getHashElement(void* key,void* data);
int hashc(void* key);


