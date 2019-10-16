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
	// delNode를 *head로 설정, *temp = *head로 설정.
	Node* delNode = *head, *temp = *head;
	
	// 삭제할 데이터 입력
	int delData;
	printf("삭제할 데이터를 입력해주세요.");
	scanf_s("%d", &delData);

	// temp를 delNode의 next로 설정. 즉, 삭제할 노드의 다음 값.
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
		printf("숫자를 입력해주세요.");
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