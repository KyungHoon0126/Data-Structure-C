#include <stdio.h>
#include <stdlib.h>

// tail X : 앞에서부터 하나넣고, 앞에서부터 하나 삭제하기

// 구조체 node
typedef struct node
{
	int data;
	struct node* next;
}Node;

int main(void)
{
	// INSERT

	// head : 첫번째 데이터 값 저장, 초기 값은 NULL
	Node* head = NULL;

	// newNode : 임시 변수 역할, 초기 값은 NULL
	Node* newNode = NULL;

	// 데이터
	int readData;

	// Node 추가 과정, 입력 값이 0이 아닐 때 까지 실행
	while (1)
	{
		scanf_s("%d", &readData);

		// readData가 0이면 종료
		if (readData == 0)
		{
			break;
		}

		// newNode 메모리 할당
		newNode = (Node*)malloc(sizeof(Node));

		// data 안에 입력 값 readData 저장
		newNode->data = readData;

		// newNode는 head를 가리킨다
		newNode->next = head;

		// head는 새로운 newNode를 가리킨다
		head = newNode;
	}

	// 출력
	/*while (1)
	{
		 head가 처음 newNode인 NULL 값이 되기 전까지 출력
		if (head == NULL)
		{
			break;
		}

		 head가 data를 가리켜서 출력 시킨다
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

		printf("%d을(를) 삭제합니다.\n", head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			head = delNextNode;

			printf("%d을(를) 삭제합니다.\n", head->data);
			free(delNode);
		}
	}
}