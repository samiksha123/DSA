#include "stackll.h"
#include <stdlib.h>
#include <stdio.h>

int push(List* list,void * element){
    int i;
    int index,res;
   index = list->length;
   res = insert(list, index, element);
   return res;
}
  
void* pop(List* list){
  int index = list->length - 1;
  void* res;
  res = deleteNode(list,index);
  return res;
};

void* peak(List* list){
  Node* head;
  void* data;
  head = list->head;
  head = head->next;
  data = head->data;
  head->previous = NULL;
  list->length--;;
  return head->data;
};