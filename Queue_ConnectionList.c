#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Node;


Node* front = NULL, * rear = NULL;


void enqueue(int input) {
	Node* newNode;

	newNode = (Node*)malloc(sizeof(Node));


	if ((front) == NULL) {
		front = newNode;
		rear = newNode;
		newNode->data = input;
	}
	else {
		rear->link = newNode;
		rear = newNode;

		newNode->data = input;
		newNode->link = NULL;
	}
}


void dequeue() {
	if (front == rear) {
		printf("Queue underflow");
	}

	Node* temp = front;
	front = temp->link;
	free(temp);
}

void print_queue() {
	Node* temp = front;

	while (temp != NULL) {
		printf("%d ", front->data);
		temp = temp->link;
	}
}

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	dequeue();
	dequeue();
	dequeue();

	print_queue();
}