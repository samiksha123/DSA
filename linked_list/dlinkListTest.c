#include "testUtils.h"
#include "dlinkList.h"
#include <stdlib.h>
#include <stdio.h>

List* list;
void setup(){
    list = create();
}
void teardown(){
    disposeList(list);
}
void test_create_node(){
    Node expected = {NULL,(void*)5,NULL};
    Node *actual = createNode(NULL,NULL);
    ASSERT(expected.next == actual->next);
    ASSERT(expected.previous == actual->previous);
}
void test_insert_data_to_list(){
    int num = 5;
    int num1 = 6;
    ASSERT(insert(list, 0, &num));
    ASSERT(insert(list, 1, &num1));
}
void test_insert_records_at_middle_of_list(){
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
    int result;
    int num = 5;
    ASSERT(insert(list, 0, &num));
    result = *(int*)deleteNode(list,0);
    ASSERT(5 == result);
}
void test_delete_middle_element_in_list(){
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
void test_hasnext_of_getiterator_gives_false_if_list_not_empty(){
        Iterator it = getIterator(list);
        ASSERT(0 == it.hasNext(&it));
}
void test_hasnext_of_getiterator_gives_true_if_list_not_empty(){
        List* list = create();
        Iterator it;
        int data[] = {100,200,300,400};
        insert(list,0,&data[0]);
        it = getIterator(list);
        ASSERT(1 == it.hasNext(&it));
}
void test_next_of_getiterator_gives_next_data(){
        List* list = create();
        Iterator it;
        int data[] = {100,200,300,400};
        insert(list,0,&data[0]);
        it = getIterator(list);
        if(it.hasNext(&it))
        ASSERT(&data[0] == it.next(&it));
}
void test_should_give_all_values_using_iterator(){
        List* list = create();
        Iterator it;
        int i = 0;
        int numbers[] = {5,10,15,20};
        insert(list, 0, numbers);
        insert(list, 1, &numbers[1]);
        insert(list, 2, &numbers[2]);
        insert(list, 3, &numbers[3]);
        it = getIterator(list);
        for(i = 0;i<it.position;i++){      
                ASSERT(numbers[i] == *(int*)it.next(&it));
        }
}