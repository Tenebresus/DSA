#include "../inc/tree.h"
#include "../inc/queue.h"

int addTreeNode(Tree *tree, int value) {

	treeNode *newNode = (treeNode*) malloc (sizeof(treeNode));
	newNode->value = value;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	Queue queue;
	queueItem *rootQueueItem = (queueItem*) malloc(sizeof(queueItem));
	rootQueueItem->treeNodePtr = tree->rootNode;
	queue.firstItem = rootQueueItem;
	queue.lastItem = rootQueueItem;	

	treeNode *parentNode = getOptimalNode(tree->rootNode, &queue);

	if (parentNode->status == STATUS_L) {
		parentNode->leftChild = newNode;
	} else {
		parentNode->rightChild = newNode;
	}

	parentNode->status++;

	return 0;
}
 
treeNode *getOptimalNode(treeNode *rootNode, Queue *queuePtr) {

	if (rootNode->status != STATUS_COMPLETE) {
		return rootNode;
	}
	
	// queue add left child

	addQueue(queuePtr, rootNode->leftChild);

	// queue add right child
	
	addQueue(queuePtr, rootNode->rightChild);

	// queue pop
	
	treeNode *poppedItem = popQueue(queuePtr);

	// recursive function call with popped queue item
	
	return getOptimalNode(poppedItem, queuePtr);
	
}
