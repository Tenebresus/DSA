#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	struct Node *nextNode;
	int value;

} Node;

void createNode(Node **previousNodePtr, int value);
bool nodeExistWithValue(Node *Node, int value); 
Node *returnNthNode(Node *headNode, int n); 

int main() {

	Node firstNode;
	firstNode.nextNode = NULL;
	firstNode.value = 10;

	Node *previousNodePtr = &firstNode;
	
	createNode(&previousNodePtr, 20);
	createNode(&previousNodePtr, 14);
	createNode(&previousNodePtr, 19);
	createNode(&previousNodePtr, 123);
	createNode(&previousNodePtr, 12);
	createNode(&previousNodePtr, 14);
	createNode(&previousNodePtr, 64);
	createNode(&previousNodePtr, 83);
	createNode(&previousNodePtr, 35);

	Node *wantedNode = returnNthNode(&firstNode, 0);

	if (wantedNode == NULL) {

		printf("Out of bounds\n");
		return 1;

	}

	printf("%d\n", wantedNode->value);

	return 0;

}

void createNode(Node **previousNodePtr, int value) {

	Node *newNodePtr = (Node*) malloc (sizeof(Node));
	newNodePtr->value = value;
	newNodePtr->nextNode = NULL;
	(*previousNodePtr)->nextNode = newNodePtr;

	*previousNodePtr = newNodePtr;

}

bool nodeExistWithValue(Node *currentNode, int value) {

	if (currentNode->value == value) {
		return true;
	}

	if (currentNode->nextNode == NULL) {
		return false;
	}

	return nodeExistWithValue(currentNode->nextNode, value);

}

Node *returnNthNode(Node *headNode, int n) {

	if (n == 0) {

		return headNode;

	}

	Node *wantedNode = headNode;


	for (int i = 0; i < n; i++){

		if (wantedNode->nextNode == NULL) {

			return NULL;

		}
		wantedNode = wantedNode->nextNode;

	}

	return wantedNode;
	

}
