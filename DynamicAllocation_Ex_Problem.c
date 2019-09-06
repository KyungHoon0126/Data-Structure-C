#include <stdio.h>
#include <stdlib.h>


// 1207 김경훈

typedef struct Information
{

	int number;
	double height;
	double weight;
	double BMI;

}people;

int BMIValue(people *student, int size)
{
	for (int i = 0; i < size; i++)
	{
		student[i].BMI = student[i].weight / (student[i].height * student[i].height);
	}
}

int main()
{
	people *student;
	
	int size;
	
	printf("동적 할당을 받을 배열의 크기: ");
	scanf_s("%d", &size);

	student = (people*)malloc(sizeof(people) * size);

	for (int i = 0; i < size; i++)
	{
		scanf_s("%d ", &student[i].number);
		scanf_s("%lf, ", &student[i].height);
		scanf_s("%lf, ", &student[i].weight);
	}

	printf("\n");

	BMIValue(student, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d번: 키:%.2lf , 몸무게:%.0lf, BMI지수:%.2lf\n", student[i].number, student[i].height, student[i].weight, student[i].BMI);
	}

	return 0;
}