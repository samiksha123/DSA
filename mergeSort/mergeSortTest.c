#include "testUtils.h"
#include "mergeSort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* first,void* second){
	return *(int*)first < *(int*)second;
}

void test_sorting_an_array_of_integers(){
    int actual[] = {4,3,1,2};
    int expected[] = {1,2,3,4};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4, compareInt);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(int*)base[i]);
}
