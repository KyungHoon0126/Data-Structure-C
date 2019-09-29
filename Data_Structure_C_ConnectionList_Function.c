#include <stdio.h>
#include <stdlib.h>

// tail : �ڿ������� �ϳ��ְ�, �ڿ������� �ϳ� �����ϱ�

// 1. insert1() : �տ������� �ϳ��ְ�, delete1() : �տ������� ��� �����ϴ°��� �Լ��� ����.
// 2. insert2() : tail�� �̿� �� �ڿ��� ����, delete2() : ȣ���� ������ �ڿ��� 1�� ������ �Լ��� ����.

typedef struct node
{
	int data;
	struct node* next; // struct node*  : �ڷ���
}Node;


//void insert1(Node** head, int readData) // �տ��� ����
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

//void delete1(Node** head) // �տ��� ����
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
		//  ���� �߿�
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