#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct treeNode {

	struct treeNode *parentNode;
	struct treeNode *leftChild;
	struct treeNode *rightChild;
	int value;

} treeNode;

typedef struct Tree {

	treeNode *rootNode;

} Tree;

treeNode *getCorrectNode(treeNode *rootTreePtr, int value); 
void addValueToTree(Tree *treePtr, int value);

#endif
