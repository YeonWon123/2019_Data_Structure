#include "List.h"
#include <assert.h>
#include <iostream>
using namespace std;

// cx7-13.cpp
// Code Example 7-13: insertion into a doubly-linked list

List::List()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}


void List::insert(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	addedNode->next = head;
	if (head) { // test to see if there was a node in the list
		head->prev = addedNode;   // if so, it needs to point back to the new node
		addedNode->prev = 0;
	}
	else {
		tail = addedNode;	// ���� head�� ���ٸ� tail�� �ʱ�ȭ
		tail->prev = 0;
		tail->next = 0;
	}
	head = addedNode;
}

void List::insertToTail(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode); // check to make sure node was allocated
	addedNode->elem = elem;
	addedNode->prev = tail;
	if (tail) {	// list was empty -- set tail
		tail->next = addedNode;
		addedNode->next = 0;
	}
	else {
		head = addedNode;
		head->prev = 0;
		head->next = 0;
	}
	tail = addedNode;

//	cout << head->elem.getName() << " " << tail->elem.getName() << "\n";
}

void List::PrintLinkedList()
{
	ListElementType elem;
	bool notEmpty(this->first(elem));
	while(notEmpty) {
		cout << "�� �̸�: " << elem.getName() << ", �׷� �ο��� : " << elem.getGroup_num()	<< ", ���� : " << elem.getTurn()
			<< ", �����ð� : " << elem.getHour()	<< ":" << elem.getMinute() << " " << elem.getAM_PM() << endl;
		notEmpty = this->next(elem);
	}
}

void List::PrintLinkedListBackward()
{
	ListElementType elem;
	bool notEmpty(this->last(elem));
	while (notEmpty) {
		cout << "�� �̸�: " << elem.getName() << ", �׷� �ο��� : " << elem.getGroup_num() << ", ���� : " << elem.getTurn()
			<< ", �����ð� : " << elem.getHour() << ":" << elem.getMinute() << " " << elem.getAM_PM() << endl;
		notEmpty = this->previous(elem);
	}
}

bool List::previous(ListElementType &elem)
{
	assert(current);

	if (current->prev == 0)
		return false;
	else {
		current = current->prev;
		elem = current->elem;
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

bool List::last(ListElementType & elem)
{
	// After calling first, current points to first item in list
	if (tail == 0)
		return false;
	else {
		elem = tail->elem;
		current = tail;
		return true;
	}
}

// node�� �����͸� ���غ��� - �̸� ��
bool List::search(string m_name)
{
	ListElementType elem;
	bool notEmpty(this->first(elem));
	while (notEmpty) {
		if (elem.getName() == m_name) {
			return true;
		}
		notEmpty = this->next(elem);
	}

	return false;
}

// Ư�� �̸��� ���� Node�� �����.
bool List::deleteNode(string m_name)
{
	if (search(m_name)) {
		// current�� ����� �ȴ�.
		Link delNode = current;
		Link delPrev = current->prev;
		Link delNext = current->next;

		if (delNode == head) {
			head = delNext;
			delNext->prev = 0;
		}
		else if (delNode == tail) {
			tail = delPrev;
			delPrev->next = 0;
		}
		else {
			delPrev->next = delNext;
			delNext->prev = delPrev;
		}

		delete delNode;
		return true;
	}
	// Ư�� data�� ������ false�� �����Ѵ�.
	return false;
}

// Ư�� Node�� �����.
bool List::deleteNode(Link nodes)
{
	// nodes�� ����� �ȴ�.
	Link delNode = nodes;
	Link delPrev = nodes->prev;
	Link delNext = nodes->next;

	if (delNode == head) {
		head = delNext;
		delNext->prev = 0;
	}
	else if (delNode == tail) {
		tail = delPrev;
		delPrev->next = 0;
	}
	else {
		delPrev->next = delNext;
		delNext->prev = delPrev;
	}

	delete delNode;
	return true;
}


// 2���� node�� swap�ϴ� �Լ�
bool List::swapLinkedList(string m_name1, string m_name2)
{
	Link node1, node2;
	if (search(m_name1)) {
		node1 = current;
	}
	else {
		return false;
	}

	if (search(m_name2)) {
		node2 = current;
	}
	else {
		return false;
	}
	
	// head�� tail�� ���� ����
	if (node1 == head && node2 == tail) {
		head = node2;
		tail = node1;
	}
	else if (node1 == tail && node2 == head) {
		head = node1;
		tail = node2;
	}
	else if (node1 == head) {
		head = node2;
	}
	else if (node1 == tail) {
		tail = node2;
	}
	else if (node2 == head) {
		head = node1;
	}
	else if (node2 == tail) {
		tail = node1;
	}

	Link ptr1, ptr2;

	/* Swap the 'next_' pointers, taking adjacency into account. */
	ptr1 = node1 == node2->next ? node2 : node2->next;
	ptr2 = node2 == node1->next ? node1 : node1->next;
	node1->next = ptr1;
	node2->next = ptr2;
	/* Swap the 'prev_' pointers, taking adjacency into account. */
	ptr1 = node1 == node2->prev ? node2 : node2->prev;
	ptr2 = node2 == node1->prev ? node1 : node1->prev;
	node1->prev = ptr1;
	node2->prev = ptr2;
	/* Fix the links from other nodes. */
	if (node1->next) node1->next->prev = node1;
	if (node1->prev) node1->prev->next = node1;
	if (node2->next) node2->next->prev = node2;
	if (node2->prev) node2->prev->next = node2;
	
	return true;
}

// 2���� node�� swap�ϴ� �Լ�
bool List::swapLinkedList(Link node1, Link node2)
{
	// ���� �� ��尡 ���ٸ� return�Ѵ�.
	if (node1 == node2) return true;

	// head�� tail�� ���� ����
	if (node1 == head && node2 == tail) {
		head = node2;
		tail = node1;
	}
	else if (node1 == tail && node2 == head) {
		head = node1;
		tail = node2;
	}
	else if (node1 == head) {
		head = node2;
	}
	else if (node1 == tail) {
		tail = node2;
	}
	else if (node2 == head) {
		head = node1;
	}
	else if (node2 == tail) {
		tail = node1;
	}

	Link ptr1, ptr2;

	/* Swap the 'next_' pointers, taking adjacency into account. */
	ptr1 = node1 == node2->next ? node2 : node2->next;
	ptr2 = node2 == node1->next ? node1 : node1->next;
	node1->next = ptr1;
	node2->next = ptr2;
	/* Swap the 'prev_' pointers, taking adjacency into account. */
	ptr1 = node1 == node2->prev ? node2 : node2->prev;
	ptr2 = node2 == node1->prev ? node1 : node1->prev;
	node1->prev = ptr1;
	node2->prev = ptr2;
	/* Fix the links from other nodes. */
	if (node1->next) node1->next->prev = node1;
	if (node1->prev) node1->prev->next = node1;
	if (node2->next) node2->next->prev = node2;
	if (node2->prev) node2->prev->next = node2;

	return true;
}

void List::merge(List & input_linkedlist)
{
	ListElementType input_head, input_tail, old_head, old_tail;
	Link link_old_tail, link_input_head;

	// �Է¹��� linkedlist�� head�� ������ � ���۵� ���� �ʰ� �Լ� ����
	if (!input_linkedlist.first(input_head)) {

		return;
	}

//	cout << input_head.getName() << endl;		// �ڹ���
//	cout << input_linkedlist.current->elem.getName() << endl;	// �̼Ҷ�

	// �Է¹��� linkedlist�� head�� �ش��ϴ� Link�� �Ҵ����
	link_input_head = input_linkedlist.current;
	// cout << "�Է¹��� linkedlist�� head�� " << link_input_head->elem.getName() << "�Դϴ�.\n";

	// ���� linkedlist�� tail�� ���� ��� �Է¹��� linkedlist�� �Ҵ��ϰ� �Լ� ����
	if (!this->last(old_tail)) {

		return;
	}
	
	link_old_tail = current;
	// cout << "���� linkedlist�� tail�� " << link_old_tail->elem.getName() << "�Դϴ�.\n";

	// ���� linkedlist�� tail�� �ִ� �Ÿ� input_linkedlist�� �����ϰ�
	// linkedlist1�� tail�� �ش��ϴ� node�� linkedlist2�� �����Ѵ�.
	// ���� linkedlist2�� head�� �ش��ϴ� node�� linkedlist1�� prev�� �����Ѵ�.
	link_old_tail->next = link_input_head;
	link_input_head->prev = link_old_tail;

	// linkedlist1�� tail�� linkedlist2�� tail�� ����
	input_linkedlist.last(input_tail);
	// cout << "�Էµ� input�� tail�� " << current->elem.getName() << "�Դϴ�\n";
	this->tail = input_linkedlist.current;

	// linkedlist2�� head�� linkedlist1�� head�� ����
	//input_linkedlist.first(input_head);
	input_linkedlist.head = head;

	// cout << "�Էµ� input�� head�� " << input_linkedlist.head->elem.getName() << "�Դϴ�\n";

	return;
}

void List::reverse()
{
	// head�� tail�� �ٲ۴�.
	ListElementType elem;
	Link link_next;
	first(elem);	// current = head�� �ȴ�.
	head = tail;
	tail = current;

	// prev�� next�� �ٲ۴�.
	bool notEmpty(first(elem));

	while (notEmpty) {
		link_next = current->next;
		current->next = current->prev;
		current->prev = link_next;

		// ���� ���� �����ѵ� ��� �Ѵ�.
		notEmpty = next(elem);
	}
}

void List::unique()
{
	ListElementType elem, elem_temp;
	Link current_link, next_link;
	bool notEmpty(this->first(elem));
	int i = 0;
	while (notEmpty) {
		current_link = current;
	//	cout << "current_link�� " << current_link->elem.getName() << endl;
		while(1) {
			current_link = current_link->next;
			if (current_link == NULL) break;
			//cout << "n��° current link" << current_link->elem.getName() << endl;
			//cout << elem.getArr_time() << " " << current_link->elem.getArr_time() << endl;
			if (elem == current_link->elem) {
				next_link = current_link->next;
				deleteNode(current_link);
				if (next_link == NULL) break;

				current_link = next_link->prev;
				//cout << "����!" << endl;
			}
			//if (current_link == tail) break;
		}
		i++;
		this->first(elem);
		for (int j = 0; j < i; j++)
			notEmpty = this->next(elem);
	//	cout << "�ϳ���" << endl;
	}
}

void List::quicksort()
{
	// first�� last�� ���ؼ� ���� quicksort�� ȣ���Ѵ�.
	ListElementType elem;
	int first_num = 0;
	int last_num = 0;

	bool notEmpty(this->first(elem));
	while (notEmpty) {
		last_num++;
		notEmpty = this->next(elem);
	}
	
	quicksort(first_num, last_num-1);
}

// index�� �̿��� Quicksort
void List::quicksort(int first, int last)
{
	if (first >= last) return;
	int lastSmall(first), i;
	ListElementType elem;
	Link link_1, link_2;
	 
	for (i = first + 1; i <= last; i++) {
		
		// i �ε����� �ִ� ��带 �̱�
		this->first(elem);
		for (int j = 0; j < i; j++)
			this->next(elem);
		link_1 = current;

		// first �ε����� �ִ� ��带 �̱�
		this->first(elem);
		for (int j = 0; j < first; j++)
			this->next(elem);
		link_2 = current;

		// ���� ���ؼ� first���� ũ�� 
		// lastsmall�� 1 ������Ų �� lastsmall�� i �ε����� �ִ� ��带 swap��
		if (link_1->elem.getArr_time() <= link_2->elem.getArr_time()) {
			++lastSmall;
			this->first(elem);
			for (int j = 0; j < lastSmall; j++)
				this->next(elem);
			link_2 = current;

			this->swapLinkedList(link_2, link_1);
		}
	}

	// ����������, lastsmall�� first�� swap��.
	int split = lastSmall;

	// first�� �ش��ϴ� ��� ã��
	this->first(elem);
	for (int j = 0; j < first; j++)
		this->next(elem);
	link_1 = current;

	// lastsmall�� �ش��ϴ� ��� ã��
	this->first(elem);
	for (int j = 0; j < lastSmall; j++)
		this->next(elem);
	link_2 = current;

	this->swapLinkedList(link_1, link_2);

	// pivot(���⼭�� split)�� �߽����� �¿� ���ȣ��
	quicksort(first, split - 1);
	quicksort(split + 1, last);
}

// node�� �̿��� quicksort (List class����, typedef Node *Link�� ������)
void List::quicksort(Link first, Link last)
{
	if (last != NULL && first != last && first != last->next)
	{
		Link pivot = partition(first, last);
	
		quicksort(first, pivot->prev);
		quicksort(pivot->next, last);
	}
}

List::Link List::partition(Link first, Link last)
{
	Link lastsmall = first;
	Link i = first->next;
	Link pivot = last->next;
	Customer object;

	for (; i != NULL; i = i->next)
	{
		if (i->elem.getArr_time() <= first->elem.getArr_time())
		{
			lastsmall = lastsmall->next;

			// swapelements(lastsmall, i);
			object = lastsmall->elem;
			lastsmall->elem = i->elem;
			i->elem = object;
		}

		if (i->next == pivot) break;
	}

	// swapelements(first, lastsmall);
	object = first->elem;
	first->elem = lastsmall->elem;
	lastsmall->elem = object;

	return lastsmall;
}