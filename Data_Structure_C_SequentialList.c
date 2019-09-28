#include <stdio.h>

void insert(int* arr) // 데이터 삽입 함수
{
	// 삽입할 데이터의 개수를 입력받는다.
	// 삽입할 데이터를 입력받고 첫 번째 인자로 전달된 주소의 리스트에 저장한다.


	// 삽입할 데이터의 개수
	int n;

	printf("삽입할 데이터 갯수 입력: ");

	// 입력 받기
	scanf_s("%d", &n);

	// 빈 공간을 찾아주기 위해서 start_index에 found 함수를 호출한다, -1을 두번째 인자로 넘겨줌으로써 빈공간을 찾는다.
	int start_index = found(arr, -1);

	//디버깅 : printf("n : %d start_index : %d start_index + n : %d\n", n, start_index, start_index + n);

	printf("삽입할 데이터 입력: ");

	// 빈공간에서 i = 0부터 i < n까지 수를 배열에 저장하는 반복문.
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[start_index + i]);
	}
}

void print(int* arr) // 데이터 출력 함수
{
	// 첫 번째 인자로 전달된 주소의 데이터를 모두 출력한다.

	// 처음부터 데이터를 출력하므로, last에 found 함수를 호출하여 끝 값을 찾아준다.
	int last = found(arr, -1);

	// i = 0부터 i는 last(-1)보다 작을 때까지 데이터를 출력한다.
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void delete(int* arr) // 데이터 삭제 함수
{
	// 1. 삭제할 데이터를 입력받고 첫 번째 인자로 전달된 주소의 리스트에서 모두 삭제 한 후
	// 2. 빈 공간을 채우기 위해 삭제된 데이터 뒤에 저장된 데이터를 한칸씩 앞으로 옮겨 저장한다.

	// 삭제할 데이터를 n을 통해 입력받는다.
	int n;

	printf("삭제할 데이터 입력: ");

	scanf_s("%d", &n);

	// 삭제할 데이터를 찾기 위해서 삭제할 데이터를 입력받은 n을 두번 째 인자로 넘겨준다, 그러면 found 함수를 이용하여 삭제할 데이터의 위치를 start로 준다.
	int start = found(arr, n);

	// 삭제할 데이터부터 끝 값인 last를 찾아주기 위해서 두 번째 인자값에 -1을 넘겨 last를 찾아준다.
	int last = found(arr, -1);

	/*for (int i = 0; i < last; i++)
	{
		if (arr[i] == n)
		{
			for (j = 0; j < 100; j++)
			{
				arr[j] = arr[j + 1];
			}
			arr[j] = -1;
		}
	}*/

	// i가 last보다 작을 때 까지 반복문을 실행한다.
	for (int i = 0; i < last; i++)
	{
		// start가 last를 넘어서기 전까지, 즉 -1을 뛰어넘을 때 까지 반복문을 실행한다.
		for (; start < last; start++)
		{
			arr[start] = arr[start + 1];
		}
	}
}

int found(int* arr, int num) // 데이터(인덱스) 조회 함수
{
	// 두 번째 인자로 전달된 숫자의 인덱스를 찾는다.
	int i = 0;

	// 데이터(인덱스)의 위치를 찾기위해서 배열에서 두 번째 인자로 넘겨받은 num이 아닐 때 까지 반복하고, 배열의 크기 100을 넘기 전까지 반복을 실행한다.
	while (arr[i] != num && arr[i] < 100)
	{
		// 디버깅 : printf("arr[i] : %d\n", arr[i]);
		i++;
	}

	return i;
}

int main() // 메인
{
	int arr[100];

	// 배열의 기본 값을 -1로 초기화 한다.
	for (int i = 0; i < 100; i++)
	{
		arr[i] = -1;
	}

	insert(arr);
	print(arr);
	insert(arr);
	print(arr);
	delete(arr);
	print(arr);
}