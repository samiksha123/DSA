#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
TreeNode* createNode(void* data){
	TreeNode* node = calloc(1, sizeof(TreeNode));
	node->parent = NULL;
	node->sibbling = NULL;
	node->children = NULL;
	node->data = data;
	return node;
}
Tree* createTree(Compare compare){
	Tree* tree = calloc(1, sizeof(Tree));
	tree->root = NULL;
	tree->Compare = compare;
	return tree;
}
int hasParent(TreeNode* treenode){
	if(NULL == treenode->parent) return 0;
	return 1;
}
int hasChild(TreeNode* treenode){
	if(NULL == treenode->children) return 0;
	return 1;
}
int hasSibling(TreeNode* treenode){
	if(NULL == treenode->sibbling) return 0;
	return 1;
}
// void* traverseInChildren(Tree* tree , TreeNode* tn , void* parentData){
// 	TreeNode* child;
// 	// if (hasChild(tn)){
// 	// 	child = tn->children;
// 	// 	if(0 == tree->Compare(child->data , parentData)) return (void*)child;
// 	// }
// 	if(hasChild(child))return  child=child->children;
// 	if (child->sibbling) return child = child->sibbling;
// 		child = child->parent ;
// 		printf(" ch sib %d\n",*(int*)child->data );
// 	if(child->sibbling) return child = child->sibbling;
// 	return NULL;
// }
void* traverseInsibling(Tree* tree , TreeNode* tn , void* parentData){
	return tn = tn->sibbling;
}
void* traverseInChildren(Tree* tree , TreeNode* tn , void* parentData){
return tn = tn->children;
}
void* traverse(Tree* tree,void* parentData ){
	TreeNode* tn;
	if(!tree->root) return 	NULL;
	tn = tree->root; 
	if(0 == tree->Compare(tn->data , parentData)) return (void*)tn;
	do{
		if(hasChild(tn)) tn = traverseInChildren(tree ,tn , parentData);
		else if(hasSibling(tn)) tn = traverseInsibling(tree, tn, parentData);
		else{
			tn = tn->parent;
			if(hasSibling(tn)) tn = tn->sibbling;
		}
		if(0 == tree->Compare(tn->data , parentData)) return (void*)tn;

	}while(tn->parent != tree->root);
	return NULL;
}
void* getchildren(Tree* tree,void* parentData){
	TreeNode* ch;
	TreeNode* parentNode = traverse(tree,parentData);
	if(parentNode == NULL) return NULL;
	ch = parentNode->children;
	return parentNode->children;
}
int insertNode(Tree* tree,void* data,void* parentData){
	TreeNode* tn = createNode(data);
	TreeNode* parentNode ,*child;
	if(tree->root == NULL){
		tree->root = tn;
		tn->parent = tree->root;
		return 1;
	}
	parentNode = traverse(tree,parentData);
	if(parentNode == NULL) return 0;
	if(parentNode->children == NULL) {
		tn->parent = parentNode;
		parentNode->children = tn;
	}
	else{
		child = parentNode->children;
		while(child->sibbling != NULL)
			child = child->sibbling;
		tn->parent = child->parent;
		child->sibbling = tn;
	}
	return 1;
}
int search(Tree* tree,void* data){
	TreeNode* tn = createNode(data);
	tn = traverse(tree,data);
	if(tn->data == data) return 1;
	return 0;
}

void* delete(Tree* tree,void* data){

	return NULL;
}