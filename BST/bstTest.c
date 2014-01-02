#include "testUtils.h"
#include "bst.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmp(void* first,void*second){
        return *(int*)first-*(int*)second;
}
void test_for_inserting_root_into_bst_and_confirming_the_data_through_getRootData(){
        BST tree=createTree(cmp);
        int a = 5;
        void* data=&a;
        ASSERT(insertInTree(&tree, data));
        ASSERT(*(int*)getRootData(tree)==*(int*)data);
}

void test_for_inserting_data_into_bst(){
        BST tree=createTree(cmp);
        int a = 5, b = 2;
        Children children;
        ASSERT(insertInTree(&tree, &a));
        ASSERT(insertInTree(&tree, &b));
        
}
       