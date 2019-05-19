#pragma once
// cx7-10.h
// Code Example 7-10: header file for list implemented with dummy head node

// the type of the individual elements in the list is defined here
typedef int ListElementType;

class List {
	// Use L to mean "this List"
public:
	List();
	// Precondition: None
	// Postcondition: L is an empty List
	void insert(const ListElementType & elem);
	// Precondition: None
	// Postcondition: Lpost = Lpre with an instance of elem added to Lpost
	bool first(ListElementType & elem);
	// Precondition: None
	// Postcondition: If the list is empty, none. Otherwise, the variable
	//    elem contains the first item in L; the "next" item to be returned
	//    is the second in L.
	// Returns: true if and only if there is at least one element in L.
	bool next(ListElementType & elem);
	// Precondition: The "first" operation has been called at least once.
	// Postcondition: Variable elem contains the next item in L, if there is one,
	//    and the next counter advances by one; if there is no next element, none.
	// Returns: true if and only if there was a next item.
	void remove(const ListElementType & target);
	// Precondition: None
	// Postcondition: Lpost = Lpre with one instance of target removed
private:
	struct Node; // declaration without definition
	typedef Node *Link; // use declaration of Node
	struct Node { // now we define Node
		ListElementType elem;
		Link next;
	};
	Link head;
	Link current;
};

