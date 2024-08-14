#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

#define STATUS_L 0
#define STATUS_R 1
#define STATUS_COMPLETE 2

typedef struct Queue Queue;

typedef struct treeNode {

	int value;
	int status;
	struct treeNode *leftChild;
	struct treeNode *rightChild;

} treeNode;

typedef struct Tree {

	treeNode *rootNode;

} Tree;

int addTreeNode(Tree *tree, int value); 
treeNode *getOptimalNode(treeNode *rootNode, Queue *queuePtr);

#endif
