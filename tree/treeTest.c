#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <String.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *a,void *b){
        return *(int*)a - *(int*)b;
}
int compareChars(void *a,void *b){
        return *(char*)a - *(char*)b;
}
void test_insert_Data_At_Root_Node(){
        int data = 10 ;
        Tree *tree = createTree(compareInts);
        ASSERT(insertNode(tree, &data, NULL));
        ASSERT(NULL == getchildren(tree,&data));
}
void test_should_not_insert_Root_Node_if_parent_data_given(){
        int data = 10 , parent = 20;
        Tree *tree = createTree(compareInts);
        ASSERT(!insertNode(tree, &data, &parent));
}
void test_should_not_insert_child_Node_if_parent_data_not_given(){
        int data[] ={10,5}; 
        Tree *tree = createTree(compareInts);
        insertNode(tree, &data[0], NULL);
        ASSERT(!insertNode(tree, &data[1],NULL));
}
void test_insert_Data_As_child_to_root_Node(){
        int data[] ={10,5,3,7,1,20}; 
        Tree *tree = createTree(compareInts);
        TreeNode *child;

        insertNode(tree, &data[0], NULL);
        insertNode(tree, &data[1],&data[0]);
        insertNode(tree, &data[2],&data[0]);
        
        child = (TreeNode*)getchildren(tree,&data[0]);
        ASSERT(&data[1] == child->data);
        child = child->sibbling;
        ASSERT(&data[2] == child->data);
}
void test_insert_Data_As_desendent_to_root_Node(){
        int data[] ={10,5,3,7,1,20}; 
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        
        insertNode(tree, &data[0], NULL);
        insertNode(tree, &data[1],&data[0]);
        insertNode(tree, &data[2],&data[1]);
        
        child = (TreeNode*)getchildren(tree,&data[1]);
        ASSERT(&data[2] == child->data);
}
void test_insert_Data_At_child_Node(){
        int data[] ={10,5,3,7,1,20}; 
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        
        insertNode(tree, &data[0], NULL);
        insertNode(tree, &data[1],&data[0]);
        insertNode(tree, &data[2],&data[0]);
        insertNode(tree, &data[3],&data[1]);
        insertNode(tree, &data[4],&data[3]);
        insertNode(tree, &data[5],&data[2]);

        child = (TreeNode*)getchildren(tree,&data[2]);
                ASSERT(&data[5] == child->data );
}
void test_search_root_node_in_tree(){
        int data[] ={10,5,3};
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        ASSERT(insertNode(tree, &data[0], NULL));
        ASSERT(search(tree, &data[0]));
}
void test_search_child_node_in_tree(){
        int data[] ={10,5,3};
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        ASSERT(insertNode(tree, &data[0], NULL));
        ASSERT(insertNode(tree, &data[1],&data[0]));
        ASSERT(insertNode(tree, &data[2],&data[0]));
        ASSERT(search(tree, &data[2]));
}
void test_remove_root_node_in_tree(){
        int data = 10;
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        ASSERT(insertNode(tree, &data, NULL));
        ASSERT(removeNode(tree, &data));
}
void test_remove_child_node_in_tree(){
        int data[] ={10,5,3};
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        ASSERT(insertNode(tree, &data[0], NULL));
        ASSERT(insertNode(tree, &data[1],&data[0]));
        ASSERT(removeNode(tree, &data[1]));
}
void test_remove_second_child_node_in_tree(){
        int data[] ={10,5,3};
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        ASSERT(insertNode(tree, &data[0], NULL));
        ASSERT(insertNode(tree, &data[1],&data[0]));
        ASSERT(insertNode(tree, &data[2],&data[0]));
        ASSERT(removeNode(tree, &data[2]));
}
void test_should_not_remove_node_that_not_exist(){
        int data[] ={10,20,30,40};
        Tree *tree = createTree(compareInts);
        TreeNode *child;
        ASSERT(insertNode(tree, &data[0], NULL));
        ASSERT(insertNode(tree, &data[1],&data[0]));
        ASSERT(!removeNode(tree, &data[2]));
}
void test_for_removing_character(){
	char data[] = {'a','b','c'};
	Tree* tree = createTree(compareChars);
	TreeNode *child;
	ASSERT(insertNode(tree,&data[0],NULL));
	ASSERT(insertNode(tree, &data[1], &data[0]));
	ASSERT(removeNode(tree, &data[1]));
}
void test_should_not_remove_root_node(){
	char data[] = {'a','b','c'};
	Tree* tree = createTree(compareChars);
	TreeNode *child;
	ASSERT(insertNode(tree,&data[0],NULL));
	ASSERT(insertNode(tree, &data[1], &data[0]));
	ASSERT(!removeNode(tree, &data[0]));
}
void test_should_remove_string(){
        String data[3];
        Tree* tree = createTree(compareChars);
        TreeNode *child;
        strcpy(data[0],"CEO");
        strcpy(data[1],"precident");
        ASSERT(insertNode(tree,&data[0],NULL));
        ASSERT(insertNode(tree, &data[1], &data[0]));
        ASSERT(removeNode(tree, &data[1]));
}
