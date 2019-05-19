// cx3-1.cpp
// Code Example 3-1: Test Driver for insertionsort Function
#include "Insertion_sort.h"

int main()
{
	const int nSize = 100;
	int a[nSize], sortedArray[nSize];

	cout << "insertionsort driver\n";
	cout << "Enter each input to max terminated by -9999\n";
	cout << "Length of input must be <= 100\n";
	int i;
	for (i = 0; i < 100; i++) {
		int val;
		cin >> val;
		if (val == -9999) // termination sentinel
			break;
		else
			a[i] = val;
	}

	InsertionSort(a, i, sortedArray);

	for (int j = 0; j < i; j++)
	{
		cout << "a[ "<< j << "] : " << a[j] << '\n';
	}
	cout << "\n\n";

	for (int j = 0; j < i; j++)
	{
		cout << "sortedArray[ " << j << "] : " << sortedArray[j] << '\n';
	}
	return 0;
}
