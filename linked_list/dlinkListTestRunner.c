#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_create_node");
	setup();
		test_create_node();
	tearDown();
	testEnded();
	testStarted("test_insert_data_to_list");
	setup();
		test_insert_data_to_list();
	tearDown();
	testEnded();
	testStarted("test_insert_records_at_middle_of_list");
	setup();
		test_insert_records_at_middle_of_list();
	tearDown();
	testEnded();
	testStarted("test_delete_first_element_in_list");
	setup();
		test_delete_first_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_delete_middle_element_in_list");
	setup();
		test_delete_middle_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_delete_end_element_in_list");
	setup();
		test_delete_end_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_hasnext_of_getiterator_gives_false_if_list_not_empty");
	setup();
		test_hasnext_of_getiterator_gives_false_if_list_not_empty();
	tearDown();
	testEnded();
	testStarted("test_hasnext_of_getiterator_gives_true_if_list_not_empty");
	setup();
		test_hasnext_of_getiterator_gives_true_if_list_not_empty();
	tearDown();
	testEnded();
	testStarted("test_next_of_getiterator_gives_next_data");
	setup();
		test_next_of_getiterator_gives_next_data();
	tearDown();
	testEnded();
	testStarted("test_should_give_all_values_using_iterator");
	setup();
		test_should_give_all_values_using_iterator();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
