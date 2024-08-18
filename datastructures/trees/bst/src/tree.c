#include "../inc/tree.h"

void addValueToTree(Tree *treePtr, int value) {

	treeNode *newNode = (treeNode *) malloc(sizeof(treeNode));
	newNode->value = value;
	newNode->rightChild = NULL;
	newNode->leftChild = NULL;

	treeNode *correctNode = getCorrectNode(treePtr->rootNode, value);
	newNode->parentNode = correctNode;

	if (value > correctNode->value) {
		correctNode->rightChild = newNode;
	} else {
		correctNode->leftChild = newNode;
	}

}

treeNode *getCorrectNode(treeNode *rootTreePtr, int value) {

		treeNode *nextNode = (value > rootTreePtr->value) ? rootTreePtr->rightChild : rootTreePtr->leftChild;
		if (!nextNode) {
			return rootTreePtr;
		}

		return getCorrectNode(nextNode, value);

}

void deleteTreeNode(Tree *tree, int value) {

	treeNode *foundNode = getNodeWithValue(tree->rootNode, value);

	if (!foundNode->leftChild && !foundNode->rightChild) {

		treeNode *parentNode = foundNode->parentNode;
		bool isLeftChild = (parentNode->leftChild == foundNode);
		
		if (isLeftChild) {
			parentNode->leftChild = NULL;
		} else {
			parentNode->rightChild = NULL;
		}

	}


}

treeNode *getNodeWithValue(treeNode *rootTreePotr, int value) {

	if (rootTreePotr->value == value) {
		return rootTreePotr;
	}

	treeNode *newNode = (value > rootTreePotr->value) ? rootTreePotr->rightChild : rootTreePotr->leftChild;
	return getNodeWithValue(newNode, value);


}
