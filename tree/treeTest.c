#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void *a,void *b){
        return *(int*)a - *(int*)b;
}

void test_insert_Data_At_Root_Node(){
	int data = 10;
	Tree *tree = createTree(compareInts);
	TreeNode *child;
	ASSERT(insertNode(tree, &data, NULL));
	ASSERT(NULL == getchildren(tree,&data));
}
void test_insert_Data_As_child_to_root_Node(){
	int data[] ={10,5,3,7,1,20}; 
	Tree *tree = createTree(compareInts);
	TreeNode *child;
	ASSERT(insertNode(tree, &data[0], NULL));
	ASSERT(insertNode(tree, &data[1],&data[0]));
	ASSERT(insertNode(tree, &data[2],&data[0]));
	child = (TreeNode*)getchildren(tree,&data[0]);
	ASSERT(&data[1] == child->data);
	child = child->sibbling;
	ASSERT(&data[2] == child->data);
}
void test_insert_Data_As_desendent_to_root_Node(){
	int data[] ={10,5,3,7,1,20}; 
	Tree *tree = createTree(compareInts);
	TreeNode *child;
	ASSERT(insertNode(tree, &data[0], NULL));
	ASSERT(insertNode(tree, &data[1],&data[0]));
	ASSERT(insertNode(tree, &data[2],&data[1]));
	child = (TreeNode*)getchildren(tree,&data[1]);
	ASSERT(&data[2] == child->data);
}
void test_insert_Data_At_child_Node(){
	int data[] ={10,5,3,7,1,20}; 
	Tree *tree = createTree(compareInts);
	TreeNode *child;
	ASSERT(insertNode(tree, &data[0], NULL));
	ASSERT(insertNode(tree, &data[1],&data[0]));
	ASSERT(insertNode(tree, &data[2],&data[0]));
	ASSERT(insertNode(tree, &data[3],&data[1]));
	ASSERT(insertNode(tree, &data[4],&data[3]));
	ASSERT(insertNode(tree, &data[5],&data[2]));
	child = (TreeNode*)getchildren(tree,&data[3]);
	ASSERT(&data[5] == child->data );
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
