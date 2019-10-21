#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Node;

Node* top = NULL;

void Push(int readData) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = readData;
	newNode->link = NULL;

	if ((top) == NULL) {
		top = newNode;
	}
	else
	{
		newNode->link = top;
		top = newNode;
	}
}

void Pop() {
	Node* temp = NULL;

	if (top == NULL) {
		printf("Stack UnderFlow");
		return -1;
	}

	if (top != NULL) {
		temp = top;
		top = top->link;
		free(temp);
	}
}

int main(void) {
	Push(1);
	Push(2);
	Push(3);
	Push(4);

	Pop();
	Pop();
	Pop();
	Pop();
}