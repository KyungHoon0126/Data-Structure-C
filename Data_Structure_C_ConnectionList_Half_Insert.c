#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;

}Node;


void insert(Node** head, int readData)
{
	// ���� : �ʱ�ȭ(newNode) �� head ���� �˻� �� head���� ������ �˻� �� while(��ġ ã��) �� �ֱ�

	// �ʱ�ȭ
	Node* newNode, *beforeNode = *head;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = readData;
	newNode->next = NULL;

	// head ���� �˻�
	if ((*head) == NULL)
	{
		*head = newNode;
		return;
	}
	
	// head���� ������ �˻�
	if ((*head)->data > readData)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	// ��ġ ã��
	while (beforeNode ->next != NULL && beforeNode->next->data < readData)
	{
		beforeNode = beforeNode->next;			
	}

	// �ֱ�
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