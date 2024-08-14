#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct treeNode treeNode;

typedef struct queueItem {

	struct queueItem *nextItem;
	treeNode *treeNodePtr;

} queueItem;

typedef struct Queue {

	queueItem *firstItem;
	queueItem *lastItem;

} Queue;

int addQueue(Queue *queue, treeNode *treeNodeItem);
treeNode *popQueue(Queue *queue);

#endif
