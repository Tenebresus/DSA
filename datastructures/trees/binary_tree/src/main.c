#include <stdio.h>
#include <stdlib.h>

#include "../inc/tree.h"

int main() {

	treeNode *rootNode = (treeNode*) malloc(sizeof(treeNode));
	rootNode->value = 10;
	rootNode->leftChild = NULL;
	rootNode->rightChild = NULL;

	Tree tree;
	tree.rootNode = rootNode;
	
	addTreeNode(&tree, 20);
	addTreeNode(&tree, 30);
	addTreeNode(&tree, 40);
	addTreeNode(&tree, 50);
	addTreeNode(&tree, 60);

	printf("%d\n", rootNode->value);
	printf("%d\n", rootNode->leftChild->value);
	printf("%d\n", rootNode->rightChild->value);
	printf("%d\n", rootNode->leftChild->leftChild->value);
	printf("%d\n", rootNode->leftChild->rightChild->value);
	printf("%d\n", rootNode->rightChild->leftChild->value);

	return 0;

}
