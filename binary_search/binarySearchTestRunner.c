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

	testStarted("test_1_search_middle_int_element_from_an_array");
	setup();
		test_1_search_middle_int_element_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_2_search_int_element_from_an_array");
	setup();
		test_2_search_int_element_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_3_search_last_element_from_an_array");
	setup();
		test_3_search_last_element_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_4_search_int_element_from_an_array_which_is_not_present");
	setup();
		test_4_search_int_element_from_an_array_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_5_search_float_element_from_an_array");
	setup();
		test_5_search_float_element_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_6_search_float_element_from_an_array_which_is_not_present");
	setup();
		test_6_search_float_element_from_an_array_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_7_search_double_element_from_an_array");
	setup();
		test_7_search_double_element_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_8_search_string_element_from_an_array");
	setup();
		test_8_search_string_element_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_9_search_character_from_an_array");
	setup();
		test_9_search_character_from_an_array();
	tearDown();
	testEnded();
	testStarted("test_10_search_e_from_the_collection_of_characters_which_is_not_found");
	setup();
		test_10_search_e_from_the_collection_of_characters_which_is_not_found();
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
