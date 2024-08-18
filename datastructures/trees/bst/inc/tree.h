#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
void deleteTreeNode(Tree *tree, int value);
treeNode *getNodeWithValue(treeNode *rootTreePotr, int value);

#endif
