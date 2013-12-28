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

	testStarted("test_insert_Data_At_Root_Node");
	setup();
		test_insert_Data_At_Root_Node();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_Root_Node_if_parent_data_given");
	setup();
		test_should_not_insert_Root_Node_if_parent_data_given();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_child_Node_if_parent_data_not_given");
	setup();
		test_should_not_insert_child_Node_if_parent_data_not_given();
	tearDown();
	testEnded();
	testStarted("test_insert_Data_As_child_to_root_Node");
	setup();
		test_insert_Data_As_child_to_root_Node();
	tearDown();
	testEnded();
	testStarted("test_insert_Data_As_desendent_to_root_Node");
	setup();
		test_insert_Data_As_desendent_to_root_Node();
	tearDown();
	testEnded();
	testStarted("test_insert_Data_At_child_Node");
	setup();
		test_insert_Data_At_child_Node();
	tearDown();
	testEnded();
	testStarted("test_search_root_node_in_tree");
	setup();
		test_search_root_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_search_child_node_in_tree");
	setup();
		test_search_child_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_remove_root_node_in_tree");
	setup();
		test_remove_root_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_remove_child_node_in_tree");
	setup();
		test_remove_child_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_remove_second_child_node_in_tree");
	setup();
		test_remove_second_child_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_should_not_remove_node_that_not_exist");
	setup();
		test_should_not_remove_node_that_not_exist();
	tearDown();
	testEnded();
	testStarted("test_for_removing_character");
	setup();
		test_for_removing_character();
	tearDown();
	testEnded();
	testStarted("test_should_not_remove_root_node");
	setup();
		test_should_not_remove_root_node();
	tearDown();
	testEnded();
	testStarted("test_should_remove_string");
	setup();
		test_should_remove_string();
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
