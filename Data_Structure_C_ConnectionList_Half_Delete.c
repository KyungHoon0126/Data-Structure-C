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

void delete(Node**head) // break point
{
	// delNode�� *head�� ����, *temp = *head�� ����.
	Node* delNode = *head, *temp = *head;
	
	// ������ ������ �Է�
	int delData;
	printf("������ �����͸� �Է����ּ���.");
	scanf_s("%d", &delData);

	// temp�� delNode�� next�� ����. ��, ������ ����� ���� ��.
	temp = delNode->next;

	while (delNode->next != NULL)
	{
		if (delNode->data == delData)
		{
			*head = delNode->next;
			free(delNode);
			return;
		}
		else if(delNode->next->data == delData)
		{
			delNode->next = delNode->next->next;
			free(temp);
			return;
		}
		temp = temp->next;
		delNode = delNode->next;
	}
}

int main(void)
{
	// insert

	Node* head = NULL;

	int readData;

	while (1)
	{
		printf("���ڸ� �Է����ּ���.");
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

	///////////////////////////////////

	// delete

	if (head == NULL)
	{
		return 0;
	}
	else
	{
		delete(&head);
	}

	return 0;
}