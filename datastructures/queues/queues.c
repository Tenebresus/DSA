#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int value;
	struct Node *nextNode;
	struct Node *previousNode;

} Node;

typedef struct Queue {

	Node *headNode;
	Node *trailingNode;

} Queue;

void enqueue(Queue *queue, int value); 
int dequeue(Queue *queue); 
int peek(Queue *queue);

int main() {

	Node *headNode = (Node *) malloc(sizeof(Node));
	headNode->value = 10;
	headNode->nextNode = NULL;

	Queue queue;
	queue.headNode = headNode;
	queue.trailingNode = headNode;

	enqueue(&queue, 20);	
	enqueue(&queue, 50);
	enqueue(&queue, 50);
	enqueue(&queue, 50);
	enqueue(&queue, 50);
	enqueue(&queue, 700);

	int firstPop = dequeue(&queue);
	dequeue(&queue);

	int peekValue = peek(&queue);

	printf("peekaboo: %d\n", peekValue);

	return 0;

}

void enqueue(Queue *queue, int value) {

	Node *newNodePtr = (Node *) malloc(sizeof(Node));
	newNodePtr->value = value;
	newNodePtr->nextNode = queue->trailingNode;
	queue->trailingNode->previousNode = newNodePtr;
	queue->trailingNode = newNodePtr;

}

int dequeue(Queue *queue) {

	int returnValue = queue->headNode->value;
	Node *newHead = queue->headNode->previousNode;
	newHead->nextNode = NULL;
	free(queue->headNode);
	queue->headNode = newHead;

	return returnValue;

}

int peek(Queue *queue){

	return queue->headNode->value;

}
