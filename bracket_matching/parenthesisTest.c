#include "testUtils.h"
#include "parenthesis.h"
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_for_round_brackets(){
	char* data = "(hello)";
	ASSERT(true == doBracketMatch(data));
}
void test_for_round_brackets_not_matching(){
	char* data = "hello)(";
	ASSERT(false == doBracketMatch(data));
}
void test_for_square_brackets(){
	char* data = "[hello]";
	ASSERT(true == doBracketMatch(data));
}
void test_for_square_brackets_not_matching(){
	char* data = "[[hello][";
	ASSERT(false == doBracketMatch(data));
}
void test_for_parenthesis_matching(){
	char* data = "{hi[he(ll)o]bye}.";
	ASSERT(true == doBracketMatch(data));
}
void test_for_parenthesis_is_not_matching(){
	char* data = "{hi[hello]bye}.[";
	ASSERT(false == doBracketMatch(data));
}
void test_for_parenthesis_is_not_matching_2(){
	char* data = "{hi[hello]welcome}.";
	ASSERT(true == doBracketMatch(data));
}
