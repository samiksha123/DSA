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

	testStarted("test_1_create_queue_for_length_of_given_size");
	setup();
		test_1_create_queue_for_length_of_given_size();
	tearDown();
	testEnded();
	testStarted("test_create_queue_for_characters");
	setup();
		test_create_queue_for_characters();
	tearDown();
	testEnded();
	testStarted("test_2_create_queue_for_float_elements");
	setup();
		test_2_create_queue_for_float_elements();
	tearDown();
	testEnded();
	testStarted("test_for_insert_int_element_at_front_of_queue");
	setup();
		test_for_insert_int_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_insert_float_element_at_front_of_queue");
	setup();
		test_for_insert_float_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_insert_character_at_front_of_queue");
	setup();
		test_for_insert_character_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_insert_string_at_front_of_queue");
	setup();
		test_for_insert_string_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_delete_element_from_front_of_queue");
	setup();
		test_for_delete_element_from_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_delete_float_element_from_front_of_queue");
	setup();
		test_for_delete_float_element_from_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_delete_character_from_front_of_queue");
	setup();
		test_for_delete_character_from_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_delete_string_from_front_of_queue");
	setup();
		test_for_delete_string_from_front_of_queue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
