#include "testUtils.h"
#include "mergeSort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* first,void* second){
	return *(int*)first < *(int*)second;
}
int compareFloat(void* first,void* second){
	return *(float*)first < *(float*)second;
}
int compareDouble(void* first,void* second){
	return *(double*)first < *(double*)second;
}

int compareChar(void* first,void* second){
	return *(char*)first < *(char*)second;
}

void test_1_sorting_an_array_of_integers(){
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4, compareInt);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(int*)base[i]);
}
void test_2_sorting_an_array_of_float(){
    float expected[] = {1,2,3,4};
    float actual[] = {4,3,1,2};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4, compareFloat);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(float*)base[i]);
}

void test_3_sorting_an_array_of_double(){
    double actual[] = {10.5f,1.5f,2.5f,7.5f};
    double expected[] = {1.5f,2.5f,7.5f,10.5f};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base,4,compareDouble);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(double*)base[i]);
}

void test_4_sorting_an_array_of_characters(){
   char actual[] = {'m','a','n','u'};
    char expected[] = {'a','m','n','u'};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base,4,compareChar);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(char*)base[i]);
}
