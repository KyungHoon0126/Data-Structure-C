#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* llink;
	struct node* rlink;
}Node;

void insert(Node** node, Node** newNode)
{
	(*newNode)->llink = (*node);
	(*newNode)->rlink = (*node)->rlink;
	(*node)->rlink->llink = (*newNode);
	(*node)->rlink = (*newNode);
}

void delete(Node** delete)
{
	(*delete)->llink->rlink = (*delete)->rlink;
	(*delete)->rlink->llink = (*delete)->llink;
}

void insertSearch(Node** head, int readData)
{
	Node* newNode;
	Node* First;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = readData;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	First = (*head);

	while (newNode->data >= First->rlink->data)
	{
		if (First->rlink == (*head))
		{
			break;
		}
		else
		{
			First = First->rlink;
		}
	}

	insert(&First, &newNode);
}

void deleteSearch(Node** head, int readData)
{
	Node* First;
	First = (*head);

	while (readData != First->rlink->data)
	{
		if (First->rlink == (*head))
		{
			return;
		}
		else
		{
			First = First->rlink;
		}
	}

	delete(&First->rlink);

}

int main(void)
{
	Node* tail = NULL;
	Node* head = (Node*)malloc(sizeof(Node));
	
	head->llink = head;
	head->rlink = head;
	head->data = 0;

	int readData;

	while (1)
	{
		scanf_s("%d", &readData);

		if (readData == 0)
		{
			break;
		}
		insertSearch(&head, readData);
	}
	deleteSearch(&head, 1);

	return 0;
}