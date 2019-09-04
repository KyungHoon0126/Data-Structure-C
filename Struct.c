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

	printf("국어점수가 가장 높은 학생이름과 점수 : %s %d", dgsw[max].name, dgsw[max].Korean);
}

int main()
{
	struct student dgsw[3];
	
	for (int i = 0; i < 3; i++)
	{
		printf("이름 : ");
		scanf_s("%s", dgsw[i].name, sizeof(dgsw[i].name));
		
		printf("점수(국어, 수학, 영어) : ");
		scanf_s("%d", &dgsw[i].Korean);
		scanf_s("%d", &dgsw[i].Math);
		scanf_s("%d", &dgsw[i].English);
	}

	max(dgsw);

	return 0;
}