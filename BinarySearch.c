#include <stdio.h>

int main(void)
{
	int arr[] = { 1, 3, 7, 9, 11, 14, 17, 19, 21 };
	int idx;
	int len = sizeof(arr) / sizeof(int);

	int first = 0;
	int last = len - 1;

	int target = 19;

	idx = binarySearch(arr, first, last, target);


	if (idx == -1)
	{
		printf("Å½»ö ½ÇÆĞ \n");
	}
	else
	{
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);
	}
}

int binarySearch(int arr[], int first, int last, int target)
{
	int mid;
	mid = (first + last) / 2;

	if (first > last)
	{
		return -1;
	}

	if (arr[mid] == target)
	{
		return mid;
	}
	
	else if (arr[mid] > target)
	{
		binarySearch(arr, first, mid - 1, target);
	}

	else
	{
		binarySearch(arr, mid + 1, last, target);
	}
}