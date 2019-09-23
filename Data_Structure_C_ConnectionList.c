#include <stdio.h>
#include <stdlib.h>

// tail X : �տ������� �ϳ��ְ�, �տ������� �ϳ� �����ϱ�

// ����ü node
typedef struct node
{
	int data;
	struct node* next;
}Node;

int main(void)
{
	// INSERT

	// head : ù��° ������ �� ����, �ʱ� ���� NULL
	Node* head = NULL;

	// newNode : �ӽ� ���� ����, �ʱ� ���� NULL
	Node* newNode = NULL;

	// ������
	int readData;

	// Node �߰� ����, �Է� ���� 0�� �ƴ� �� ���� ����
	while (1)
	{
		scanf_s("%d", &readData);

		// readData�� 0�̸� ����
		if (readData == 0)
		{
			break;
		}

		// newNode �޸� �Ҵ�
		newNode = (Node*)malloc(sizeof(Node));

		// data �ȿ� �Է� �� readData ����
		newNode->data = readData;

		// newNode�� head�� ����Ų��
		newNode->next = head;

		// head�� ���ο� newNode�� ����Ų��
		head = newNode;
	}

	// ���
	/*while (1)
	{
		 head�� ó�� newNode�� NULL ���� �Ǳ� ������ ���
		if (head == NULL)
		{
			break;
		}

		 head�� data�� �����Ѽ� ��� ��Ų��
		printf("%d", head->data);

		head = head->next;
	}*/


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//DELETE

	if (head == NULL)
	{
		return 0;
	}
	else
	{
		Node* delNode, * delNextNode;

		delNode = head;
		delNextNode = delNode->next;
		head = delNextNode;

		printf("%d��(��) �����մϴ�.\n", head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			head = delNextNode;

			printf("%d��(��) �����մϴ�.\n", head->data);
			free(delNode);
		}
	}
}