#include "dlinkList.h"
#include <stdlib.h>

List* create(){
   List *list = malloc(sizeof(List));
   list->length = 0;
   list->head = NULL;
   return list;
}
Node* createNode(void* previous,void* next){
   Node* node = calloc(1,sizeof(Node));
   node->previous = previous;
   node->next = next;
   return node;
}
int insert(List* list,int index,void * element){
   int i;
   Node *prevNode,*nextNode,*nodeToAdd;
   if(index > list->length) 
      return 0;
   list->length++;
   nodeToAdd = createNode(NULL,NULL);
   nodeToAdd->data = element;
   prevNode = list->head;
  if(list->head == NULL){
    nextNode = NULL;
    list->head = nodeToAdd;
  }
  else
    nextNode = prevNode->next;
  for(i=1;i<index;i++){
      nextNode = prevNode->next;
      prevNode = nextNode->previous;
  }
  nodeToAdd->previous = prevNode;
  if(prevNode != NULL)
      prevNode->next = nodeToAdd;
  nodeToAdd->next = nextNode;
  return 1;
}
void* deleteNode(List* list,int index){
  int i;
  Node *head;
  if(index > list->length-1)
    return 0;
  head = list->head;
  for(i=0;i<index;i++){
    head = head->next;
  }
  if(index==0){   
    list->length--;
    return head->data;
  }
  if(index==list->length-1){
    head->previous = NULL;
    list->length--;
    return head->data;
  }
  head->previous = head->next;
  head->next = head->previous;
  free(head);
  list->length--;
  return head->data;
};
