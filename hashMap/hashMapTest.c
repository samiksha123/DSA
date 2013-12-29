#include "testUtils.h"
#include "hashMap.h"
#include <stdio.h>
#include <string.h>

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
	String value ="Samiksha";
	String value2 = "manali";
	HashMap *hm = createHashMap(hashcode,compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(&value == get(hm,&key));
	ASSERT(&value2 == get(hm,&key2));
}
void test_for_insert_data_into_bucket(){
	int key = 10,key2 = 20;
	int value = 100,value2 = 200;
	HashMap *hm = createHashMap(hashcode, compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(get(hm, &key) == &value);
	ASSERT(get(hm, &key2) == &value2);
}
void test_for_putting_data_into_bucket(){
	int key = 10,key2 = 20;
	int value = 100,value2 = 200;
	HashMap *hm = createHashMap(hashcode, compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(get(hm, &key) == &value);
	ASSERT(get(hm, &key2) == &value2);
}
void test_remove_an_element_to_hashmap(){
        Data* data;
        int key = 1,key2 = 2;
        String value="samiksha" , value2 ="manali";
        HashMap* hm = createHashMap(hashcode, compareKeys);
        ASSERT(put(hm, &key , &value));
        ASSERT(put(hm, &key2 , &value2));
        ASSERT(removeData(hm, &key));
        ASSERT(get(hm, &key) == NULL);
        ASSERT(get(hm, &key2) == &value2);
        
}