#include "bst.h"
#include <stdlib.h>

typedef struct BSTNode{
    void* data;
    struct BSTNode* parent;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
}BSTNode;

BST createTree(CompareInTree* cmp){
    BST tree ={NULL,cmp};
    return tree;
}

BSTNode* createBTNode(void* dataToInsert, BSTNode* parent){
    BSTNode* node = malloc(sizeof(BSTNode));
    node->leftChild=node->rightChild=NULL;
    node->parent=parent;
    node->data=dataToInsert;
    return node;
}

void* getRootData(BST tree){
    return ((BSTNode*)tree.root)->data;
}

BSTNode* getParent(BSTNode* node,void* data,CompareInTree* cmp){
    int cmpResult=cmp(node->data,data);
    if(cmpResult == 0) return NULL;
    if(cmpResult > 0){
        if(!node->leftChild) return node; 
        return getParent(node->leftChild, data, cmp);
    }
    if(!node->rightChild) return node; 
    return getParent(node->rightChild, data, cmp);
}

int insertInTree(BST* tree, void* dataToInsert){
    BSTNode *pNode;
    if(!tree->root){
        tree->root=createBTNode(dataToInsert, NULL);
        return 1;
    }
    pNode = getParent(tree->root,dataToInsert,tree->cmp);
    if(!pNode) return 0;
    if(tree->cmp(pNode->data,dataToInsert)>0)
        pNode->leftChild=createBTNode(dataToInsert, pNode);
    else
        pNode->rightChild=createBTNode(dataToInsert, pNode);
    return 1;
}

