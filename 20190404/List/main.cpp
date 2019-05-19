// cx7-4.cpp
// Code Example 7-4: simple List client

#include "list.h" // header for Linear List; ListElementType is int
#include <iostream>
using namespace std;

int main()
{
	list l;
	ListElementType i; // header file defines this to be int
	cout << "Enter items to add to list, add 0 to stop: ";
	cin >> i;

	while (i != 0) {
		l.insert(i);
		cin >> i;
	}
	cout << "Here are the items in the list.\n";
	ListElementType elem;
	bool notEmpty(l.first(elem));
	while (notEmpty) {
		cout << elem << endl;
		notEmpty = l.next(elem);
	}
	return 0;
}



