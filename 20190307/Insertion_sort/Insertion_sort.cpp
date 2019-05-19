#include "Insertion_sort.h"

void InsertionSort(int a[], const int nElement, int SortedArray[])
{
	// for문에서 한개씩 뽑기
	for (int i = 0; i < nElement; i++)
	{
		InsertElement(a[i], SortedArray, i);
	}
	return;
}

void InsertElement(int value, int SortedArray[], int SortedArraySize)
{
	for (int i = 0; i < SortedArraySize; i++)
	{
		if (SortedArray[i] > value)
		{
			for (int j = SortedArraySize; j > i; j--)
			{
				SortedArray[j] = SortedArray[j - 1];
			}
			SortedArray[i] = value;
			return;
		}
	}

	SortedArray[SortedArraySize] = value;
	return;
}