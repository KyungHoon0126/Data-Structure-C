#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = 0; // front : 앞, rear : 끝

// 삽입
void enqueue(int readData) {
	if ((rear + 1) % MAX == front) {
		printf("Queue overflow\n");
		return;
	}
	rear = ++rear % MAX;
	queue[rear] = readData;
}

// 삭제
int dequeue() {
	if (front == rear) {
		printf("Queue underflow \n");
		return -1;
	}
	front = ++front % MAX;
	return queue[front];
}

void print_queue(void) {
	
	int i;
	for (i = front; i != rear; i = ++i % MAX) {
		printf("%d ", queue[(i + 1) % MAX]);
	}

	/*if ((front + 1) == rear) {
		printf("%d ", rear);
	}*/
}

int main(void) {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	printf("dequeue : %d\n", dequeue());
	printf("dequeue : %d\n", dequeue());

	enqueue(5);

	print_queue();

	return 0;
}