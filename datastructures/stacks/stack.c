#include <stdlib.h>
#include <stdio.h>

typedef struct Node {

	int value;
	struct Node *nextNode;

} Node;


typedef struct Stack {
	
	Node *headNode;

} Stack; 

void pushToStack(Stack *stack, int value); 
void popStack(Stack *stack); 
int peek(Stack *stack);

int main() {

	Node headNode;
	headNode.nextNode = NULL;
	headNode.value = 10;

	Stack stack;
	stack.headNode = &headNode;

	pushToStack(&stack, 15);
	pushToStack(&stack, 58);
	pushToStack(&stack, 112);
	pushToStack(&stack, 30);
	pushToStack(&stack, 234);
	pushToStack(&stack, 17);
	
	popStack(&stack);
	popStack(&stack);
	popStack(&stack);

	int headNodeValue = peek(&stack);
	printf("%d\n", headNodeValue);

	return 0;

}

void pushToStack(Stack *stack, int value) {

	Node *newNodePtr = (Node*) malloc(sizeof(Node));

	newNodePtr->value = value;
	newNodePtr->nextNode = stack->headNode;

	stack->headNode = newNodePtr;
	
}

void popStack(Stack *stack) {

	Node *newHeadNode = stack->headNode->nextNode;
	free(stack->headNode);
	stack->headNode = newHeadNode;

}

int peek(Stack *stack){

	return stack->headNode->value;

}
