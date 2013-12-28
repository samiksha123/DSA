#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"
const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern prajakta = {123,"prajakta",18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;
	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);
	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));
	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_insert_element_at_the_last(){
	Intern kavita = {111,"kavita",18};
	Intern prajakta = {110,"prajakta",19};
	add(internsPtr,&prateek);
	add(internsPtr,&kavita);
	add(internsPtr,&prajakta);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&kavita == get(internsPtr, 1));
	ASSERT(&prajakta == get(internsPtr, 2));
}
void test_should_search_element_in_list(){
	int result = insert(internsPtr, 0, &prateek);
	int res;
	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	res = search(internsPtr, &prateek);
	ASSERT(res == SUCCESS);
}
void test_should_not_search_element_in_list(){
	int result = insert(internsPtr, 0, &prateek);
	int res;
	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	res = search(internsPtr, &prajakta);
	ASSERT(res == FAILURE);
}

void test_should_remove_element_from_the_list(){
	void* res;
	Intern kavita = {111,"kavita",18};
	Intern prajakta = {110,"prajakta",19};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr,1,&kavita);
	insert(internsPtr,2,&prajakta);
    res = removee(internsPtr,1);
	ASSERT(&kavita == res);
}
void test_should_not_remove_element_from_the_list(){
	void* res;
	Intern kavita = {111,"kavita",18};
	Intern prajakta = {110,"prajakta",19};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr,1,&kavita);
	insert(internsPtr,2,&prajakta);
    res = removee(internsPtr,3);
	ASSERT(NULL == res);
}
