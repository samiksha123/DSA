#include "testUtils.h"
#include "bst.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmp(void* first,void*second){
        return *(int*)first-*(int*)second;
}
void test_for_inserting_root_into_bst_and_confirming_through_getRootData(){
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
 		ASSERT(searchInTree(tree,&b));
        children=getChildrenData(&tree, &a);
        ASSERT(children.right==NULL);
        ASSERT(*(int*)children.left==2);
}

void test_inserting_data_to_bst_and_confirming_through_get_children_data(){
        BST tree=createTree(cmp);
        int a = 5, b = 2,c = 6;
        Children children;
        ASSERT(insertInTree(&tree, &a));
        ASSERT(insertInTree(&tree, &b));
        ASSERT(insertInTree(&tree, &c));
        ASSERT(searchInTree(tree,&b));
        children=getChildrenData(&tree, &a);
        ASSERT(*(int*)children.right==6);
        ASSERT(*(int*)children.left==2);
}

void test_inserting_data_to_bst_at_different_levels(){
        BST tree=createTree(cmp);
        int a = 5, b = 2,c = 6, d = 3;
        Children children;
        ASSERT(insertInTree(&tree, &a));
        ASSERT(insertInTree(&tree, &b));
        ASSERT(insertInTree(&tree, &c));
        ASSERT(insertInTree(&tree, &d));
        ASSERT(searchInTree(tree,&b));
        children=getChildrenData(&tree, &b);
        ASSERT(*(int*)children.right==3);
        ASSERT(children.left==NULL);
}