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
void test_for_putting_data(){
	int key =10;
	int key2 = 56;
	String value ="Samiksha";
	String value2 = "manali";
	HashMap *hm = createHashMap(hashc,compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(&value == get(hm,&key));
	ASSERT(&value2 == get(hm,&key2));
}
void test_for_insert_data_into_bucket(){
	int key = 10,key2 = 25;
	int value = 100,value2 = 200;
	HashMap *hm = createHashMap(hashc, compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(get(hm, &key) == &value);
	ASSERT(get(hm, &key2) == &value2);
}
void test_for_putting_data_into_bucket(){
	int key = 10,key2 = 20;
	int value = 100,value2 = 200;
	HashMap *hm = createHashMap(hashc, compareKeys);
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(get(hm, &key) == &value);
	ASSERT(get(hm, &key2) == &value2);
}
void test_remove_an_element_from_hashmap(){
        HashElement* data;
        int key = 55,key2 = 99;
        String value="samiksha" , value2 ="manali";
        HashMap* hm = createHashMap(hashc, compareKeys);
        ASSERT(put(hm, &key , &value));
        ASSERT(put(hm, &key2 , &value2));
        ASSERT(removeData(hm,&key));
        ASSERT(get(hm, &key) == NULL);
        ASSERT(get(hm, &key2) == &value2);
}
void test_should_give_iterator_of_keys(){
        int key = 11,key2 = 25,i;
        Iterator it;
        int value=11 , value2 =22;
        HashMap* hm = createHashMap(hashc, compareKeys);
        ASSERT(put(hm,&key,&value));
        ASSERT(put(hm,&key2,&value2));
        it = keys(hm);
        while(it.hasNext(&it))
        ASSERT(value == *(int*)it.next(&it));
}
void test_should_give_iterator_of_keys2(){
        int key[4] = {1,2,3,4},i;
        Iterator it;
        int value[4]={11,22,33,44};
        HashMap* hm = createHashMap(hashc, compareKeys);
        for(i = 0;i < 4;i++){
           ASSERT(put(hm,&key[i],&value[i]));
        }
        it = keys(hm);
        for(i = 0;i < 4;i++){
           while(it.hasNext(&it))
           ASSERT(key[i] == *(int*)it.next(&it));
        }
}
void test_rehash_keys_in_hashmap(){
        Iterator it;
        int i = 0 ,key[] = {30 ,40,50,60};
        char* values[] ={"AAA","BBB","CCC","DDD"};
        int afterRehashing[] ={40,60,30,50};
        HashMap* map = createHashMap(hashc, compareKeys);
        for(i = 0 ; i < 4 ;i++ )
                ASSERT(put(map, &key[i] , &values[i]));
        it = keys(map);
        i = 0;
        while(it.hasNext(&it)){
                ASSERT(& key[i] == it.next(&it));
                i++;
        }
        rehash(map);
        it = keys(map);
        i = 0;
        while(it.hasNext(&it)){
                ASSERT(& afterRehashing[i] == it.next(&it));
                i++;
        }
}
