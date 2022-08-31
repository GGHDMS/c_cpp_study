#include<iostream>
using namespace std;


void insertionSort(char *a[], int low, int high)
{
	int i, j;
	char *key;
	for (i = 1; i < high+1; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && (strcmp(a[j], key) == 1))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
