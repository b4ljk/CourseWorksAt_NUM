#include "sort.h"
void read(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insertion_sort(int a[], int n)
{
	int i, j, key;
	for (j = 1; j < n; j++)
	{
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}

void selection_sort(int a[], int n)
{
	int i, j, min, temp, k;
	for (i = 0; i < n; i++)
	{
		min = a[i];

		for (j = i + 1; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				k = j;
			}
		}
		temp = a[i];
		a[i] = min;
		a[k] = temp;
	}
}

void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
