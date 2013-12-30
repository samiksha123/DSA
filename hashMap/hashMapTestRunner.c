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

	testStarted("test_for_putting_data");
	setup();
		test_for_putting_data();
	tearDown();
	testEnded();
	testStarted("test_for_insert_data_into_bucket");
	setup();
		test_for_insert_data_into_bucket();
	tearDown();
	testEnded();
	testStarted("test_for_putting_data_into_bucket");
	setup();
		test_for_putting_data_into_bucket();
	tearDown();
	testEnded();
	testStarted("test_remove_an_element_from_hashmap");
	setup();
		test_remove_an_element_from_hashmap();
	tearDown();
	testEnded();
	testStarted("test_should_give_iterator_of_keys");
	setup();
		test_should_give_iterator_of_keys();
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
