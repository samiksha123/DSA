#include "testUtils.h"
#include "dlinkList.h"
#include <stdlib.h>
#include <stdio.h>
void test_create_node(){
    Node expected = {NULL,(void*)5,NULL};
    Node *actual = createNode(NULL,NULL);
    ASSERT(expected.next == actual->next);
    ASSERT(expected.previous == actual->previous);
}
void test_insert_data_to_list(){
    List* list = create();
    int num = 5;
    int num1 = 6;
    ASSERT(insert(list, 0, &num));
    ASSERT(insert(list, 1, &num1));
}
void test_insert_records_at_middle_of_list(){
    List* list = create();
    int num = 5;
    int num1 = 6;
    int num2 = 5;
    int num3 = 6;
    ASSERT(insert(list, 0, &num));
    ASSERT(insert(list, 1, &num1));
    ASSERT(insert(list, 1, &num2));
    ASSERT(insert(list, 2, &num3));
}
void test_delete_first_element_in_list(){
     List* list = create();
    int result;
    int num = 5;
    ASSERT(insert(list, 0, &num));
    result = *(int*)deleteNode(list,0);
    ASSERT(5 == result);
}
void test_delete_middle_element_in_list(){
    List* list = create();
    int num = 5;
    int num1 = 6;
    int num2 = 5;
    int result;
    int res,res1,res2,res3;
    ASSERT(insert(list, 0, &num));
    ASSERT(insert(list, 1, &num1));
    ASSERT(insert(list, 1, &num2));
    result = *(int*)deleteNode(list,1);
    ASSERT(5 == result);
}
void test_delete_end_element_in_list(){
    List* list = create();
    int num = 5;
    int num1 = 6;
    int result,result1;
    ASSERT(insert(list, 0, &num));
    ASSERT(insert(list, 1, &num1));
    result = *(int*)deleteNode(list,1);
    ASSERT(6 == result);
    ASSERT(insert(list,1,&num));
    result1 = *(int*)deleteNode(list,1);
    ASSERT(5 == result1);
}