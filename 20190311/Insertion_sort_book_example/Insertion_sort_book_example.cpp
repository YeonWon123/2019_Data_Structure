#include "Insertion_sort_book_example.h"

void insertionSort(int a[], int n)
{
	// Precondition: a is an array with subscripts ranging from 0 to n-1
	int i;
	for (i = 1; i < n; i++)
		// Loop invariant: items in range from 0 to i-1 are sorted; 
		//      items from i to n-1 have not yet been examined.
		insertNextItem(a, i); // see cx3-6.cpp
// Postcondition: array a is sorted
}

// cx3-6.cpp
// Code Example 3-6: insertNextItem (used by Insertion Sort)

void insertNextItem(int a[], int i)
{
	// Precondition: array a is sorted from 0 to i-1
	int newItem(a[i]), insertPos(i);
	for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
		// Loop Invariant: newItem <= a[insertPos+1] .. a[i] &&
		//                  a[insertPos+1] .. a[i] are sorted
		a[insertPos] = a[insertPos - 1];
	a[insertPos] = newItem;
	// Postcondition: array a is sorted from 0 to i
}