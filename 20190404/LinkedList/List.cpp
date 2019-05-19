#include "pch.h"
#include "List.h"
#include <assert.h>
#include <iostream>
using namespace std;

List::List()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}

List::~List()
{
	while (head != 0) {
		Link delNode = head;
		head = head->next;
		delete delNode;
	}
}

void List::printlist()
{
	while (head != 0) {
		Link delNode = head;
		head = head->next;
		cout << delNode->elem << " ";
	}
}

void List::insert(const ListElementType & elem)
{
	Link addedNode(new Node);
	assert(addedNode);
	addedNode->elem = elem;
	if (head == 0 || elem <= head->elem) {
		addedNode->next = head;
		head = addedNode;
		if (head == 0)
			tail = addedNode;
	}
	else {
		Link pred(head);
		while (pred->next != 0 && pred->next->elem <= addedNode->elem) {
			pred = pred->next;
		}

		addedNode->next = pred->next;
		pred->next = addedNode;

		// tail ¼³Á¤
		if (addedNode->next == NULL)
			tail = addedNode;
	}
}


/*
void List::insert(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode); // check to make sure node was allocated
	addedNode->elem = elem;
	if (head == 0) // list was empty -- set head
		head = addedNode;
	else
		tail->next = addedNode;
	tail = addedNode;
	addedNode->next = 0;
}
*/
/*
void List::insert(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode); // check to make sure node was allocated
	addedNode->elem = elem;
	if (head == 0) {
		// list was empty -- set tail
		tail = addedNode;
	}
	addedNode->next = head;
	head = addedNode;
}
*/
/*
void List::insert(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode); // check to make sure node was allocated
	addedNode->elem = elem;
	if (tail == 0)
		// list was empty -- set tail
		tail = addedNode;
	else
		head->next = addedNode;
	head = addedNode;
	addedNode->next = 0;
}
*/
bool List::first(ListElementType & elem)
{
	// After calling first, current points to first item in list
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}
bool List::next(ListElementType & elem)
{
	// with proper use, current should always be nonzero
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}

