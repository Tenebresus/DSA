#include <stdio.h>

#include "../inc/tree.h"

int main() {

	treeNode *rootNode = (treeNode *) malloc(sizeof(treeNode));
	rootNode->leftChild = NULL;
	rootNode->rightChild = NULL;
	rootNode->parentNode = NULL;
	rootNode->value = 10;

	Tree tree;
	tree.rootNode = rootNode;

	addValueToTree(&tree, 20);
	addValueToTree(&tree, 15);
	addValueToTree(&tree, 8);

	deleteTreeNode(&tree, 8);

	return 0;

}
