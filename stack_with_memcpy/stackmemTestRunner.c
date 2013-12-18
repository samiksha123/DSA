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

	testStarted("test_1_create_stack_for_length_of_given_size");
	setup();
		test_1_create_stack_for_length_of_given_size();
	tearDown();
	testEnded();
	testStarted("test_2_create_stack_for_float");
	setup();
		test_2_create_stack_for_float();
	tearDown();
	testEnded();
	testStarted("test_3_create_stack_for_char");
	setup();
		test_3_create_stack_for_char();
	tearDown();
	testEnded();
	testStarted("test_4_push_int_element_at_top_of_stack");
	setup();
		test_4_push_int_element_at_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_5_push_float_element_at_top_of_stack");
	setup();
		test_5_push_float_element_at_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_7_pop_int_element_at_top_of_stack");
	setup();
		test_7_pop_int_element_at_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_8_pop_float_element_at_top_of_stack");
	setup();
		test_8_pop_float_element_at_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_9_pop_float_element_at_top_of_stack");
	setup();
		test_9_pop_float_element_at_top_of_stack();
	tearDown();
	testEnded();
	testStarted("test_10_should_give_top_element");
	setup();
		test_10_should_give_top_element();
	tearDown();
	testEnded();
	testStarted("test_10_should_give_top_float_element");
	setup();
		test_10_should_give_top_float_element();
	tearDown();
	testEnded();
	testStarted("test_11_if_stack_is_full");
	setup();
		test_11_if_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_12_if_stack_is_empty");
	setup();
		test_12_if_stack_is_empty();
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
