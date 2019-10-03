#include <stdio.h>
#include <stdlib.h>

// typedef로 구조체 선언
typedef struct node
{
	int data;

	// struct node라는 자료형으로 *next라는 포인터 변수 선언.
	// *next인 이유는 다음 newNode의 주소값을 저장하기 위해서이다.
	struct node* next;

}Node;

// [정렬 연결 리스트 로직] : insert 함수 : 초기화(newNode) → head 존재 검사 → head보다 작은지 검사 → while(위치 찾기) → 넣기

// insert : 입력 받을 함수, Node** : 이중 포인터, head의 주소값의 값의 주소값을 넘겨주기 위해서 사용.
void insert(Node** head, int readData)
{
	// Node 자료형을 이용하여 newNode와 beforeNode 포인터 변수 선언.
	Node* newNode, * beforeNode = *head;

	// newNode의 메모리 할당을 통해 값을 넣을 저장 공간 생성.
	newNode = (Node*)malloc(sizeof(Node));

	// newNode의 이중포인터 연결 -> 실제 값으로 이동해 data안에 readData를 저장.
	newNode->data = readData;

	// newNode의 next값을 NULL로 초기화 시켜준다.
	newNode->next = NULL;

	// head가 NULL이 아닐 때, *head를 고정시킬 newNode를 넣어준다.
	if ((*head) == NULL)
	{
		(*head) = newNode;

		// return을 해주는 이유는 *head는 초기값만 설정하고 더 이상 필요가 없기 때문에 return을 해준다.
		return;
	}

	// newNode->data = readData, 둘 중 아무거나 써도 됨.
	if (newNode->data < (*head)->data)
	{
		// newNode->next로 head를 설정. 즉 *head는 모든 Data(Node는 하나인데, Node안의 Data들의 모든 주소)를 가지고 있는 거지.
		newNode->next = (*head);

		// *head를 다시 newNode 즉, 새로운 제일 작은값의 Node를 head가 가리키게 설정.
		(*head) = newNode;

		// return 필수
		return;
	}

	// beforeNode->next가 NULL인지 아닌지를 판별하는 이유는 마지막 Node의 data랑 비교했을 때 그 다음 수로 넣어야 한다면, 그 다음 값에 아무것도 없기때문에 넣어줄 수 없다. 즉 NULL값을 참조해서 넣을수가 없다.
	// 그리고 beforeNode의 next의 data가 readData보다 작은지를 확인한다.
	while (beforeNode->next != NULL && beforeNode->next->data < readData)
	{
		// 그렇게 되면 beforeNode를 beforeNode의 next로 만들어서 값을 넣어 줄 수 있다.
		beforeNode = beforeNode->next;
	}

	// 새로 들어오는 값의 next를 beforeNode의 next로 해주면, newNode가 기존의 beforeNode의 data에 연결된다. [뒷 부분 연결]
	newNode->next = beforeNode->next;

	// beforeNode의 next를 newNode를 주어서, beforeNode의 next뒤에 newNode data가 연결된다. [앞 부분 연결]
	beforeNode->next = newNode;
}

int main(void)
{
	// Node = struct node, 즉 Node라는 자료형을 선언하고 head라는 변수명을 지어준다. 그리고 초기값은 NULL을 준다.
	Node* head = NULL;

	// 입력받을 데이터
	int readData;

	// readData가 0일때 까지 계속 입력받는다.
	while (1)
	{
		scanf_s("%d", &readData);

		if (readData == 0)
		{
			// readData가 0이면 break;
			break;
		}
		else
		{
			// readData가 0이 아니면 insert 함수를 호출하고, head의 직접적인 값을 다루기 위해서 주소값을 넘기고, readData를 넘겨준다.
			insert(&head, readData);
		}
	}
	// breakpoint로 디버깅	
	return 0;
}