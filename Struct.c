#include <stdio.h>

struct student
{
	char name[10];
	int Korean;
	int Math;
	int English;
};

int max(struct student dgsw[])
{
	int max = 0;
	
	for (int i = 0; i < 3; i++)
	{
		if (dgsw[max].Korean < dgsw[i].Korean)
		{
			max = i;
		}
	}

	printf("���������� ���� ���� �л��̸��� ���� : %s %d", dgsw[max].name, dgsw[max].Korean);
}

int main()
{
	struct student dgsw[3];
	
	for (int i = 0; i < 3; i++)
	{
		printf("�̸� : ");
		scanf_s("%s", dgsw[i].name, sizeof(dgsw[i].name));
		
		printf("����(����, ����, ����) : ");
		scanf_s("%d", &dgsw[i].Korean);
		scanf_s("%d", &dgsw[i].Math);
		scanf_s("%d", &dgsw[i].English);
	}

	max(dgsw);

	return 0;
}