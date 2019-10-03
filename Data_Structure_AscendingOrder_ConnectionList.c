#include <stdio.h>
#include <stdlib.h>

// typedef�� ����ü ����
typedef struct node
{
	int data;

	// struct node��� �ڷ������� *next��� ������ ���� ����.
	// *next�� ������ ���� newNode�� �ּҰ��� �����ϱ� ���ؼ��̴�.
	struct node* next;

}Node;

// [���� ���� ����Ʈ ����] : insert �Լ� : �ʱ�ȭ(newNode) �� head ���� �˻� �� head���� ������ �˻� �� while(��ġ ã��) �� �ֱ�

// insert : �Է� ���� �Լ�, Node** : ���� ������, head�� �ּҰ��� ���� �ּҰ��� �Ѱ��ֱ� ���ؼ� ���.
void insert(Node** head, int readData)
{
	// Node �ڷ����� �̿��Ͽ� newNode�� beforeNode ������ ���� ����.
	Node* newNode, * beforeNode = *head;

	// newNode�� �޸� �Ҵ��� ���� ���� ���� ���� ���� ����.
	newNode = (Node*)malloc(sizeof(Node));

	// newNode�� ���������� ���� -> ���� ������ �̵��� data�ȿ� readData�� ����.
	newNode->data = readData;

	// newNode�� next���� NULL�� �ʱ�ȭ �����ش�.
	newNode->next = NULL;

	// head�� NULL�� �ƴ� ��, *head�� ������ų newNode�� �־��ش�.
	if ((*head) == NULL)
	{
		(*head) = newNode;

		// return�� ���ִ� ������ *head�� �ʱⰪ�� �����ϰ� �� �̻� �ʿ䰡 ���� ������ return�� ���ش�.
		return;
	}

	// newNode->data = readData, �� �� �ƹ��ų� �ᵵ ��.
	if (newNode->data < (*head)->data)
	{
		// newNode->next�� head�� ����. �� *head�� ��� Data(Node�� �ϳ��ε�, Node���� Data���� ��� �ּ�)�� ������ �ִ� ����.
		newNode->next = (*head);

		// *head�� �ٽ� newNode ��, ���ο� ���� �������� Node�� head�� ����Ű�� ����.
		(*head) = newNode;

		// return �ʼ�
		return;
	}

	// beforeNode->next�� NULL���� �ƴ����� �Ǻ��ϴ� ������ ������ Node�� data�� ������ �� �� ���� ���� �־�� �Ѵٸ�, �� ���� ���� �ƹ��͵� ���⶧���� �־��� �� ����. �� NULL���� �����ؼ� �������� ����.
	// �׸��� beforeNode�� next�� data�� readData���� �������� Ȯ���Ѵ�.
	while (beforeNode->next != NULL && beforeNode->next->data < readData)
	{
		// �׷��� �Ǹ� beforeNode�� beforeNode�� next�� ���� ���� �־� �� �� �ִ�.
		beforeNode = beforeNode->next;
	}

	// ���� ������ ���� next�� beforeNode�� next�� ���ָ�, newNode�� ������ beforeNode�� data�� ����ȴ�. [�� �κ� ����]
	newNode->next = beforeNode->next;

	// beforeNode�� next�� newNode�� �־, beforeNode�� next�ڿ� newNode data�� ����ȴ�. [�� �κ� ����]
	beforeNode->next = newNode;
}

int main(void)
{
	// Node = struct node, �� Node��� �ڷ����� �����ϰ� head��� �������� �����ش�. �׸��� �ʱⰪ�� NULL�� �ش�.
	Node* head = NULL;

	// �Է¹��� ������
	int readData;

	// readData�� 0�϶� ���� ��� �Է¹޴´�.
	while (1)
	{
		scanf_s("%d", &readData);

		if (readData == 0)
		{
			// readData�� 0�̸� break;
			break;
		}
		else
		{
			// readData�� 0�� �ƴϸ� insert �Լ��� ȣ���ϰ�, head�� �������� ���� �ٷ�� ���ؼ� �ּҰ��� �ѱ��, readData�� �Ѱ��ش�.
			insert(&head, readData);
		}
	}
	// breakpoint�� �����	
	return 0;
}