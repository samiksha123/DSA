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

void test_for_sorting_an_integer_elements(){
    int actual[] = {4,3,1,2};
    int expected[] = {1,2,3,4};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4, compareInt);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(int*)base[i]);
}

void test_for_sorting_an_float_elements(){
    float actual[] = {4.3f,3.2f,1.1f,2.6f};
    float expected[] = {1.1f,2.6f,3.2f,4.3f};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4, compareFloat);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(float*)base[i]);
}
void test_for_sorting_an_double_elements(){
    double actual[] = {10.50000,1.50000,2.50000,7.50000};
    double expected[] = {1.50000,2.50000,7.50000,10.50000};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base,4,compareDouble);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(double*)base[i]);
}

void test_for_sorting_characters(){
	char actual[] = {'a','n','d','e'};
	char expected[] = {'a','d','e','n'};
	int i;
	void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base,4,compareChar);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(char*)base[i]);
}

