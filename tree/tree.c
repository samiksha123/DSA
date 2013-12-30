#include "tree.h"
#include <stdlib.h>
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
int hasSibbling(TreeNode* treenode){
    if(NULL == treenode->sibbling) return 0;
    return 1;
}
void* traverseInside(Tree* tree , TreeNode* tn){
    if(hasChild(tn)) return tn->children;
    if(hasSibbling(tn)) return tn->sibbling;
    do{
            tn = tn->parent;
            if(hasSibbling(tn))  return tn->sibbling;
    }while(!tn->sibbling && tn->parent != tree->root);
    return NULL;
}
void* traverse(Tree* tree,void* parentData ){
    TreeNode* tn = tree->root;
    if(0 == tree->Compare(tn->data , parentData)) return tn;
    do{
            tn = traverseInside(tree , tn);
            if(NULL == tn) return NULL;
            if(0 == tree->Compare(tn->data , parentData)) return tn;
    }while(tn != tree->root);
    return tn;
}
int insertNode(Tree* tree,void* data,void* parentData){
    TreeNode* tn = createNode(data);
    TreeNode* parentNode ,*child;
    if(tree->root == NULL ){
            if(parentData != NULL) return 0;
            tree->root = tn;
            tn->parent = tree->root;
            return 1;
    }
    if(parentData == NULL) return 0;
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
void* getchildren(Tree* tree,void* parentData){
    TreeNode* ch;
    TreeNode* parentNode = traverse(tree,parentData);
    if(parentNode == NULL) return NULL;
    ch = parentNode->children;
    return parentNode->children;
}
int removeNode(Tree* tree,void* data){
    TreeNode* tn,*parent;
    tn = traverse(tree, data);
    if(NULL == tn) return 0;
    if(!tn->children){
            parent = tn->parent;
            parent->children = tn->sibbling;
            return 1;
    }        
    return 0;
}
void dispose(Tree* tree){
	free(tree);
}
