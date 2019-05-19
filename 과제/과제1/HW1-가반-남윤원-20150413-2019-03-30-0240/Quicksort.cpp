#include "Quicksort.h"

// cx6-6.cpp
// Code Example 6-6: Quicksort
// Note: this quicksort function depends upon the partition function in cx6-7.cpp
void quicksort(Customer a[], int first, int last)
{
	// precondition: a is an array; 
	//    The portion to be sorted runs from index first to index last inclusive.
	if (first >= last) // Base Case -- nothing to sort, so just return
		return;
	// Otherwise, we¡¯re in the recursive case.
	// The partition function uses the item in a[first] as the pivot
	// and returns the position of the pivot -- split -- after the partition.
	int split(partition(a, first, last));

	// Recursively, sort the two partitions.
	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
	// postcondition: a is sorted in ascending order 
	// between first and last inclusive.
}


// cx6-7.cpp
// Code Example 6-7: Partition function (for quicksort, cx6-6.cpp)
int partition(Customer a[], int first, int last)
{
	int lastSmall(first), i;

	for (i = first + 1; i <= last; i++)
		// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
		//    a[lastSmall+1]...a[i-1] > a[first]

		if (a[i] <= a[first]) { // key comparison
			++lastSmall;
			swapElements(a, lastSmall, i);
		}

	swapElements(a, first, lastSmall); // put pivot into correct position
	// postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
	//    a[lastSmall+1]...a[last] > a[lastSmall]
	return lastSmall; // this is the final position of the pivot -- the split index
}


void swapElements(Customer a[], int first, int last)
{
	Customer temp = a[first];
	a[first] = a[last];
	a[last] = temp;
}
