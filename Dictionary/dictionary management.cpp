#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 20
#define MAX_MEANING_SIZE 50

// element Ÿ�� ���� 
typedef struct {
	char word[MAX_WORD_SIZE];   // key
	char meaning[MAX_MEANING_SIZE];
} element;

// Ʈ���� ��� Ÿ�� ����ü ����
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;
// ����Ž��Ʈ�� ����ü ����
typedef struct BST {
	TreeNode *root;
}BST;

// ����Ž��Ʈ���� �ʱ�ȭ
void init(BST *T)
{
	T->root = NULL;
}

TreeNode *search(TreeNode *treePtr, char *word);
int searchItem(BST *T, char *word, element *item)
{
	TreeNode *treePtr = search(T->root, word);
	if (treePtr == NULL)
		return 0;
	else {
		*item = treePtr->data;
		return 1;
	}
}
// ��͸� �̿��� �ܾ�(Ű) Ž��
TreeNode *search(TreeNode *treePtr, char *word)
{
	while (treePtr != NULL) {
		if (strcmp(word, treePtr->data.word) == 0)
			return treePtr;
		else if (strcmp(word, treePtr->data.word) < 0)
			treePtr = treePtr->left;
		else
			treePtr = treePtr->right;
	}
	return NULL; // Ž���� �������� ��� NULL ��ȯ
}

// �ܾ� �� �ٲٱ�
/*void replace(BST *T, char *word, char *meaning)
{
	TreeNode *treePtr = search(T->root, word);
	treePtr -> data.
}*/

// ����Ž��Ʈ����  ���� item�� ����
void insert_node(TreeNode **treePtr, element item);
void insertItem(BST *T, element item)
{
	insert_node(&(T->root), item);
}

// ��͸� �̿��� ���һ���
void insert_node(TreeNode **treePtr, element item)
{
	if (*treePtr == NULL) {
		*treePtr = (TreeNode *)malloc(sizeof(TreeNode));
		(*treePtr)->data = item;
		(*treePtr)->left = (*treePtr)->right = NULL;
	}
	else if (strcmp(item.word, (*treePtr)->data.word) < 0)
		insert_node(&((*treePtr)->left), item);
	else if (strcmp(item.word, (*treePtr)->data.word) > 0)
		insert_node(&((*treePtr)->right), item);
}

// word�� �ܾ ������ ��带 ã�� �̸� ������ 
void delete_node(TreeNode **root, char *word)
{
	TreeNode *parent, *child, *succ, *succ_parent, *treePtr;
	// word�� �ܾ ������ ��� treePtr�� Ž�� 
	// parent�� treePtr�� �θ���
	parent = NULL;
	treePtr = *root;
	while (treePtr != NULL &&
		strcmp(word, treePtr->data.word)) {
		parent = treePtr;
		treePtr = (strcmp(word, treePtr->data.word) < 0) ?
			treePtr->left : treePtr->right;
	}
	// Ž���� ����� ������ treePtr�� NULL�̸� Ʈ���ȿ� 
	// word�� ����
	if (treePtr == NULL) { // Ž��Ʈ���� ���� �ܾ�
		printf("key is not in the tree");
		return;
	}
	// ù��° ���: �ܸ������ ���
	if ((treePtr->left == NULL) && (treePtr->right == NULL)) {
		if (parent != NULL) {
			// �θ����� �ڽ��ʵ带 NULL�� �����.
			if (parent->left == treePtr)
				parent->left = NULL;
			else parent->right = NULL;
		}
		else// ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = NULL;
	}
	// �ι�° ���: �ϳ��� �ڽĸ� ������ ���
	else if ((treePtr->left == NULL) ||
		(treePtr->right == NULL)) {
		child = (treePtr->left != NULL) ?
			treePtr->left : treePtr->right;
		if (parent != NULL) {
			if (parent->left == treePtr)// �θ� �ڽİ� ���� 
				parent->left = child;
			else parent->right = child;
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = child;
	}
	// ����° ���: �ΰ��� �ڽ��� ������ ���
	else {
		// ������ ����Ʈ������ successor(�İ���: �ּ� Ű�� ���)�� ã�´�.
		succ_parent = treePtr;
		succ = treePtr->right;
		// successor�� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		// successor�� �θ�� �ڽ��� ���� 
		if (succ_parent->left == succ)
			succ_parent->left = succ->right;
		else
			succ_parent->right = succ->right;
		// successor�� �����͸� ���� ��忡 ����
		treePtr->data = succ->data;
		// successor ����
		treePtr = succ;
	}
	free(treePtr);
}
// ����Ž��Ʈ������ �ܾ� word�� ����
void delete_node(TreeNode **root, char *word);
void deleteItem(BST *T, char *word)
{
	delete_node(&(T->root), word);
}

void print(TreeNode *root)
{
	if (root != NULL) {
		print(root->left);
		printf("%s %s\n", root->data.word, root->data.meaning);
		print(root->right);
	}
}
// ����Ž��Ʈ������ ���ĺ� ������� �ܾ�� ���� ���   
void printAll(BST *T)
{
	print(T->root);
}


int main()
{
	BST T;
	element item;
	char command[15];
	char meaning;
	init(&T);

	while (1) {  // do
		scanf("%s", command);
		if (strcmp(command, "�ܾ����") == 0) {
			scanf("%s", item.word);
			scanf("%s", item.meaning);
			insertItem(&T, item);
		}

		else if (strcmp(command, "�ܾ�˻�") == 0) {
			scanf("%s", item.word);
			if (searchItem(&T, item.word, &item))
				printf("%s\n", item.meaning);
			else
				printf("Error1\n");
		}
		else if (strcmp(command, "�ܾ����") == 0) {
			scanf("%s", item.word);
			if (!searchItem(&T, item.word, &item))
				printf("Error2\n");
			else
				deleteItem(&T, item.word);
		}

		/*//�ܾ� �� ���� �߰� - ����
				 else if(strcmp(command, "�ܾ�溯��") == 0) {
					   scanf("%s", item.word);
					   scanf("%s\n", item.meaning);
			   if (searchItem(&T, item.word, &item))
						   item.meaning = meaning;
				   }*/

		else if (strcmp(command, "��ü�ܾ����") == 0) {
			printAll(&T);
		}
		else if (strcmp(command, "����") == 0) {
			break;
		}

	}  // while (strcmp(command,"����") == 0)

	return 0;
}



