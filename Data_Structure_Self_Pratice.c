#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

void insert(Node** head, int readData)
{
	Node* newNode, * beforeNode = *head;

	newNode = (Node*)malloc(sizeof(Node));

	newNode->data = readData;

	newNode->next = NULL;

	if ((*head) == NULL)
	{
		(*head) = newNode;
		return;
	}

	if (newNode->data < (*head)->data)
	{
		newNode->next = (*head);
		(*head) = newNode;
		return;
	}

	while (beforeNode->next != NULL && beforeNode->next->data < readData)
	{
		beforeNode = beforeNode->next;
	}

	newNode->next = beforeNode->next;
	beforeNode->next = newNode;
}

int main(void)
{
	Node* head = NULL;

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
			insert(&head, readData);
		}
	}
	
	return 0;
}