// cx9-1.cpp
// Code Example 9-1: Queue example

#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	char c;
	Queue < char > q;

	// read characters until '.' found, adding each to Q and S.
	while (1) {
		cin >> c;
		if (c == '.') break; // when '.' entered, leave the loop
		q.enqueue(c);
	}
	while (!q.isEmpty()) {
		cout << "Q: " << q.dequeue() << '\t';
	}

	return 0;
}
