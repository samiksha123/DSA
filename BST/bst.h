typedef int CompareInTree(void* first, void* second);
typedef struct{
    void* root;
    CompareInTree* cmp;
} BST;

typedef struct {
    void* left;
    void* right;
} Children;

BST createTree(CompareInTree* cmp);
void* getRootData(BST tree);
int insertInTree(BST* tree, void* dataToInsert);
int deleteFromTree(BST* tree, void* data);
int searchInTree(BST tree, void* nodeData);
Children getChildrenData(BST * tree, void* parentData);