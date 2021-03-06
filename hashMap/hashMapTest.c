#include "testUtils.h"
#include "hashMap.h"
#include <stdio.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

HashMap* hm;
int compareKeys(void* key1,void* key2){
        return *(int*)key1 - *(int*)key2;
}
void setup(){
        hm = createHashMap(hashc,compareKeys);
}
// void tearDown(){
//         disposeMap(hm);
// }
void test_for_putting_data(){
	int key =10;
	int key2 = 56;
	String value ="Samiksha";
	String value2 = "manali";
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(&value == get(hm,&key));
	ASSERT(&value2 == get(hm,&key2));
}
void test_for_insert_data_into_bucket(){
	int key = 10,key2 = 25;
	int value = 100,value2 = 200;
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(get(hm, &key) == &value);
	ASSERT(get(hm, &key2) == &value2);
}
void test_for_putting_data_into_bucket(){
	int key = 10,key2 = 20;
	int value = 100,value2 = 200;
	ASSERT(put(hm,&key,&value));
	ASSERT(put(hm,&key2,&value2));
	ASSERT(get(hm, &key) == &value);
	ASSERT(get(hm, &key2) == &value2);
}
// void test_remove_an_element_from_hashmap(){
//         HashElement* data;
//         int key = 55,key2 = 99;
//         String value="samiksha" , value2 ="manali";
//         HashMap* hm = createHashMap(hashc, compareKeys);
//         ASSERT(put(hm, &key , &value));
//         ASSERT(put(hm, &key2 , &value2));
//         ASSERT(removeData(hm,&key));
//         ASSERT(get(hm, &key) == NULL);
//         ASSERT(get(hm, &key2) == &value2);
// }
void test_should_give_iterator_of_keys(){
        int key = 11,key2 = 25,i=0;
        Iterator it;
        int value=11 , value2 =22;
        ASSERT(put(hm,&key,&value));
        ASSERT(put(hm,&key2,&value2));
        it = keys(hm);
        ASSERT(key == *(int*)it.next(&it));
        ASSERT(key2 == *(int*)it.next(&it));
}
void test_should_give_iterator_of_keys2(){
        int key[4] = {1,2,3,4},i=0;
        Iterator it;
        int value[4]={11,22,33,44};
        for(i = 0;i < 4;i++){
           ASSERT(put(hm,&key[i],&value[i]));
        }
        it = keys(hm);
       ASSERT(1 == *(int*)it.next(&it));
       ASSERT(4 == *(int*)it.next(&it));
       ASSERT(3 == *(int*)it.next(&it));
       ASSERT(2 == *(int*)it.next(&it));
}
// void test_rehash_keys_in_hashmap(){
//         Iterator it;
//         int i = 0 ,key[] = {30 ,40,50,60};
//         char* values[] ={"AAA","BBB","CCC","DDD"};
//         int afterRehashing[] ={40,60,30,50};
//         for(i = 0 ; i < 4 ;i++ )
//                 ASSERT(put(hm, &key[i] , &values[i]));
//         it = keys(hm);
//         i = 0;
//         while(it.hasNext(&it)){
//                 ASSERT(key[i] == *(int*)it.next(&it));
//                 i++;
//         }
//         rehash(hm);
//         it = keys(hm);
//         i = 0;
//          while(it.hasNext(&it))
//             printf("%d\n",*(int*)it.next(&it));
//         //  {
//         //         ASSERT(afterRehashing[i] == *(int*)it.next(&it));
//         //         i++;
//         // }
// }
void test_rehash_keys_in_hashmap(){
    Iterator it;
    int i = 0 ,key[] = {30 ,40,50,60};
    char* values[] ={"AAA","BBB","CCC","DDD"};
    int afterRehashing[] ={40,60,30,50};
    for(i = 0 ; i < 4 ;i++ )
        ASSERT(put(hm, &key[i] , &values[i]));
    it = keys(hm);
    i = 0;
    rehash(hm);
    it = keys(hm);
    while(it.hasNext(&it)){
            ASSERT(afterRehashing[i] == *(int*)it.next(&it));
            i++;
    }
}