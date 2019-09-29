#include <stdio.h>
#include <stdlib.h>

// tail : 뒤에서부터 하나넣고, 뒤에서부터 하나 삭제하기

// 1. insert1() : 앞에서부터 하나넣고, delete1() : 앞에서부터 모두 삭제하는것을 함수로 구현.
// 2. insert2() : tail을 이용 → 뒤에서 삽입, delete2() : 호출할 때마다 뒤에서 1개 삭제를 함수로 구현.

typedef struct node
{
	int data;
	struct node* next; // struct node*  : 자료형
}Node;


//void insert1(Node** head, int readData) // 앞에서 삽입
//{
//	Node* newNode;
//	newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = readData;
//	newNode->next = NULL;
//
//	if (*head == NULL)
//	{
//		*head = newNode;
//	}
//	else
//	{
//		newNode->next = *head;
//		*head = newNode;
//	}
//}

//void delete1(Node** head) // 앞에서 삭제
//{
//	Node* delNode, * delNextNode;
//	delNode = NULL, delNextNode = NULL;
//
//	if (*head)
//	{
//		delNode = *head;
//		delNextNode = delNode->next;
//		*head = delNextNode;
//		free(delNode);
//	}
//
//	while (delNextNode != NULL)
//	{
//		delNode = delNextNode;
//		*head = delNextNode;
//
//		delNextNode = delNextNode->next;
//		free(delNode);
//	}
//}


void insert2(Node** head, Node** tail, int readData)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));

	newNode->data = readData;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		(*tail)->next = newNode;
	}

	*tail = newNode;
}

void delete2(Node** head, Node** tail)
{
	Node* delNode = NULL, * delBeforeNode = NULL;

	delNode = *head;

	while (delNode->next != NULL)
	{
		//  순서 중요
		delBeforeNode = delNode;
		delNode = delNode->next;
	}

	*tail = delBeforeNode;
	
	if ((*tail) != NULL)
	{
		(*tail)->next = NULL;
	}
	else
	{
		*head = NULL;
	}

	free(delNode);
}


int main(void)
{
	Node* head, *tail;
	head = NULL, tail = NULL;
	int readData;

	while (1)
	{
		scanf_s("%d", &readData);

		if (readData == 0)
		{
			break;
		}
		else
		{
			// insert1()
			// insert1(&head, readData);
			
			// insert2()
			insert2(&head, &tail, readData);
		}
	}
	

	if (head == NULL)
	{
		return 0;
	}
	else
	{
		// delete1(&head);

		delete2(&head, &tail);
		delete2(&head, &tail);
		delete2(&head, &tail);
	}

	return 0;
}