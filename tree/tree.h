typedef int (*Compare)(void* element1,void* element2);

typedef struct Tree{
	void* root;
	int (*Compare)(void* element1,void* element2);
}Tree;

typedef struct TreeNode{
	void* parent;
	void* sibbling;
	void* children;
	void* data;
}TreeNode;

Tree* createTree(Compare compare);
TreeNode* createNode(void* data);
int insertNode(Tree* tree,void* data,void* parentData);
void* traverse(Tree* tree,void* parentData );
void* getchildren(Tree* tree,void* parentData);
int search(Tree* tree,void* data);