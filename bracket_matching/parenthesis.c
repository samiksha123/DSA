#include "parenthesis.h"
#include <string.h>
#include <stdbool.h>
bool doBracketMatch(char* data){
	int i;
	Stack* stack = create(sizeof(char),3);
	for(i = 0; i<strlen(data); i++)
	{
		switch(data[i]){
			case '{' :
			case '[' :
			case '(' :
				push(stack,&data[i]);
				break;
			case '}' :
				if(*(char*)top(stack) == '{') pop(stack) ;
				else push(stack,&data[i]);
				break;
			case ']' :
				if(*(char*)top(stack) == '[') pop(stack) ;
				else push(stack,&data[i]);
				break;
			case ')' :
 				if(*(char*)top(stack) == '(') pop(stack) ;
				else push(stack,&data[i]);
				break;
		}
	}
	if(stack->top == -1)
		return true;
	return false;
}