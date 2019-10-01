#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;

}Node;


void insert(Node** head, int readData)
{
	// 순서 : 초기화(newNode) → head 존재 검사 → head보다 작은지 검사 → while(위치 찾기) → 넣기

	// 초기화
	Node* newNode, *beforeNode = *head;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = readData;
	newNode->next = NULL;

	// head 존재 검사
	if ((*head) == NULL)
	{
		*head = newNode;
		return;
	}
	
	// head보다 작은지 검사
	if ((*head)->data > readData)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	// 위치 찾기
	while (beforeNode ->next != NULL && beforeNode->next->data < readData)
	{
		beforeNode = beforeNode->next;			
	}

	// 넣기
	newNode->next = beforeNode->next;
	beforeNode->next = newNode;
}


int main(void)
{
	Node* head = NULL;
	int readData=0;

	while (1)
	{
		scanf_s("%d", &readData);

		if (readData == 0)
		{
			break;
		}
		else
		{
			insert(&head, readData);
		}
	}

	return 0;
}