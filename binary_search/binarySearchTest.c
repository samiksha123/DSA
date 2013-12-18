#include "testUtils.h"
#include "binarySearch.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble (void* a, void* b){
    return (*(double*)a - *(double*)b);
}
int compareChar(void* a, void* b){
        return (*(char*)a - *(char*)b);
}
int compareString(void *a, void *b){ 
         return (strcmp((char *)a,(char *)b));
}

void test_1_search_middle_int_element_from_an_array(){
    int elements[7] = {1,2,3,4,5,6,7};
    int key = 3;
    int* result = binarySearch(elements,&key, 7, sizeof(int), compareInt);
    ASSERT(3 == *result);
    ASSERT(&elements[2] == result);
};
void test_2_search_int_element_from_an_array(){
    int elements[5] = {1,2,3,4,5};
    int key = 1;
    int* result = binarySearch(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(1 == *result);
    ASSERT(&elements[0] == result);
};
void test_3_search_last_element_from_an_array(){
    int elements[5] = {1,2,3,4,5};
    int key = 5;
    int* result = binarySearch(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(5 == *result);
    ASSERT(&elements[4] == result);
};
void test_4_search_int_element_from_an_array_which_is_not_present(){
    int elements[3] = {1,2,3};
    int key = 4;
    int* result = binarySearch(elements,&key, 3, sizeof(int), compareInt);
    ASSERT((int*)result == NULL);
};
void test_5_search_float_element_from_an_array(){
    float elements[5] = {1.1f,2.2f,3.3f,4.4f,5.5f};
    float key = 4.4f;
    float* result = binarySearch(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(4.4f == *result);
    ASSERT(&elements[3] == result);
};
void test_6_search_float_element_from_an_array_which_is_not_present(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 4.6f;
    float* result = binarySearch(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(NULL == (float*)result);
};
void test_7_search_double_element_from_an_array(){
    double elements[5] = {1.0,2.0,3.0,4.0,5.0};
    double key = 3.0;
    double* result = binarySearch(elements,&key, 5, sizeof(double), compareDouble);
    ASSERT(3.0 == *result);
    ASSERT(&elements[2] == result);
};

void test_8_search_string_element_from_an_array(){
    String elements[3] = {"pallavi","samiksha","sayali"};
    String key = "samiksha";
    String* result = binarySearch(elements,&key, 3, sizeof(String), compareString);
    printf("%d",(strcmp("samiksha",*result)));
    ASSERT(!(strcmp("samiksha",*result)));
    ASSERT(&elements[1] == result);
};
void test_9_search_character_from_an_array(){
    char elements[3] = {'a','b','c'};
    char key = 'b';
    char* result = binarySearch(elements,&key, 3, sizeof(char), compareChar);
    ASSERT('b' == *result);
    ASSERT(&elements[1] == result);
};
void test_10_search_e_from_the_collection_of_characters_which_is_not_found(){
    char elements[3] = {'a','b','c'};
    char key = 's';
    char* result = binarySearch(elements,&key, 3, sizeof(char), compareChar);
    ASSERT(NULL == (char*)result);
};