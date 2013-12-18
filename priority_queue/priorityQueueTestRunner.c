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

	testStarted("test_for_create_a_new_queue");
	setup();
		test_for_create_a_new_queue();
	tearDown();
	testEnded();
	testStarted("test_for_adding_integer_element");
	setup();
		test_for_adding_integer_element();
	tearDown();
	testEnded();
	testStarted("test_for_adding_char_element");
	setup();
		test_for_adding_char_element();
	tearDown();
	testEnded();
	testStarted("test_for_adding_string_element");
	setup();
		test_for_adding_string_element();
	tearDown();
	testEnded();
	testStarted("test_for_remove_integer_element_from_queue");
	setup();
		test_for_remove_integer_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_for_remove_float_element_from_queue");
	setup();
		test_for_remove_float_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_for_remove_character_from_queue");
	setup();
		test_for_remove_character_from_queue();
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
