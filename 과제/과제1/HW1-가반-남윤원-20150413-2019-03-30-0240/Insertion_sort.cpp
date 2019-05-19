#include "Insertion_sort.h"

void insertionSort(Customer a[], int n)
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

void insertNextItem(Customer a[], int i)
{
	// Precondition: array a is sorted from 0 to i-1
	Customer newItem_cus = a[i];
	int newItem(a[i].getArr_time()), insertPos(i);
	for (; insertPos && newItem < a[insertPos - 1].getArr_time(); insertPos--)
		// Loop Invariant: newItem <= a[insertPos+1] .. a[i] &&
		//                  a[insertPos+1] .. a[i] are sorted
		a[insertPos] = a[insertPos - 1];
	a[insertPos] = newItem_cus;
	// Postcondition: array a is sorted from 0 to i
}