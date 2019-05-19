// cx3-1.cpp
// Code Example 3-1: Test Driver for insertionsort Function
#include <iostream>
using namespace std;

void insertionsort(int a[], int n);

int main()
{
	int a[100], i;

	cout << "insertionsort driver\n";
	cout << "Enter each input to max terminated by -9999\n";
	cout << "Length of input must be <= 100\n";
	for (i = 0; i < 100; i++) {
		int val;
		cin >> val;
		if (val == -9999) // termination sentinel
			break;
		else
			a[i] = val;
	}

	insertionsort(a, i);

	for (int j = 0; j < i; j++)
	{
		cout << "a[ "<< j << "] : " << a[j] << '\n';
	}
	cout << "\n\n";
	return 0;
}
