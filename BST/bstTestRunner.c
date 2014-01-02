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

	testStarted("test_for_inserting_root_into_bst_and_confirming_through_getRootData");
	setup();
		test_for_inserting_root_into_bst_and_confirming_through_getRootData();
	tearDown();
	testEnded();
	testStarted("test_for_inserting_data_into_bst");
	setup();
		test_for_inserting_data_into_bst();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_to_bst_and_confirming_through_get_children_data");
	setup();
		test_inserting_data_to_bst_and_confirming_through_get_children_data();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_to_bst_at_different_levels");
	setup();
		test_inserting_data_to_bst_at_different_levels();
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
