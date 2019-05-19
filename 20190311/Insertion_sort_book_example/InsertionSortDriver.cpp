// cx3-1.cpp
// Code Example 3-1: Test Driver for insertionsort Function
#include "Insertion_sort_book_example.h"

#define Driver1
//#define Driver2

#ifdef Driver1
int main()
{
	const int nSize = 100;
	int a[nSize];

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

	insertionSort(a, i);

	for (int j = 0; j < i; j++)
	{
		cout << "a[ "<< j << "] : " << a[j] << '\n';
	}
	cout << "\n\n";

	return 0;
}
#endif

#ifdef Driver2
int main()
{
	int N;
	cout << "입력될 정수의 개수를 입력: ";
	cin >> N;
	int *arr = new int[N];

	cout << N << "개의 정수를 입력: ";
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	insertionSort(arr, N);
	
	for (int i = 0; i < N; i++)
	{
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}

	delete arr;
	return 0;
}
#endif