#include "../inc/queue.h"

int addQueue(Queue *queue, treeNode *treeNodeItem) {

	queueItem *newQueueItem = (queueItem*) malloc(sizeof(queueItem));
	newQueueItem->treeNodePtr = treeNodeItem;
	queue->lastItem->nextItem = newQueueItem;
	queue->lastItem = newQueueItem;

	return 0;

}

treeNode *popQueue(Queue *queue){

	queueItem *firstItem = queue->firstItem;
	treeNode *returnNode = firstItem->treeNodePtr;
	queue->firstItem = firstItem->nextItem;
	free(firstItem);
	return returnNode;

}
