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

	testStarted("test_add_data_to_empty_stack");
	setup();
		test_add_data_to_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_push_data_to_list");
	setup();
		test_push_data_to_list();
	tearDown();
	testEnded();
	testStarted("test_push_float_data_to_list");
	setup();
		test_push_float_data_to_list();
	tearDown();
	testEnded();
	testStarted("test_push_char_data_to_list");
	setup();
		test_push_char_data_to_list();
	tearDown();
	testEnded();
	testStarted("test_delete_last_element_in_list");
	setup();
		test_delete_last_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_delete_float_element_in_list");
	setup();
		test_delete_float_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_delete_char_element_in_list");
	setup();
		test_delete_char_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_top_element_in_stack");
	setup();
		test_top_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_top_char_element_in_stack");
	setup();
		test_top_char_element_in_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
