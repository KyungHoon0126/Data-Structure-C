#include <stdio.h>
#include <stdlib.h>

// void *malloc(size_t size); stdlib.h ���� ������ �ʿ� ����.

int main()
{
	int size;

	printf("�����Ҵ��� ���� �迭�� ũ��: ");
	scanf_s("%d", &size);


	// malloc�� void*(���̵� ������) ��ȯ���̹Ƿ� (int*)�� �� ��ȯ�� ���־�� ��.
	int* arr = (int*) malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	
	printf("\n���:");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}