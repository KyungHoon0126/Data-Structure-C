#include <stdio.h>
#include <stdlib.h>

// void *malloc(size_t size); stdlib.h 쓰면 적어줄 필요 없다.

int main()
{
	int size;

	printf("동적할당을 받을 배열의 크기: ");
	scanf_s("%d", &size);


	// malloc이 void*(보이드 포인터) 반환형이므로 (int*)로 형 변환을 해주어야 함.
	int* arr = (int*) malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	
	printf("\n출력:");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}