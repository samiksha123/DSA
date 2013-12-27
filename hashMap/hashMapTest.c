#include "testUtils.h"
#include "hashMap.h"
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int key;
	String value;
} Intern;

Intern prateek = {1, "Prateek"};
Intern prajakta = {2,"prajakta"};
int compareKeys(void* key1,void* key2){
	return *(int*)key1 - *(int*)key2;
}
int hashcode(void* key,int capacity){
	int hash;
	hash = *(int*)key % capacity;
	return hash;
}
void test_for_putting_data(){
	int key =10;
	int key2 = 20;
	Data* data,*data1;
	String value ="Samiksha";
	String value2 = "manali";
	HashMap *hm = createHashMap(hashcode,compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(put(hm,&key2,&value2));
	data = getData(&key,&value);
	ASSERT(&key == data->key);
	ASSERT(&value == data->value);
}