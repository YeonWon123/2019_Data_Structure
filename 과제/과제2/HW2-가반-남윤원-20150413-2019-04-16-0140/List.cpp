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
		tail = addedNode;	// 만약 head가 없다면 tail을 초기화
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
		cout << "고객 이름: " << elem.getName() << ", 그룹 인원수 : " << elem.getGroup_num()	<< ", 순번 : " << elem.getTurn()
			<< ", 도착시간 : " << elem.getHour()	<< ":" << elem.getMinute() << " " << elem.getAM_PM() << endl;
		notEmpty = this->next(elem);
	}
}

void List::PrintLinkedListBackward()
{
	ListElementType elem;
	bool notEmpty(this->last(elem));
	while (notEmpty) {
		cout << "고객 이름: " << elem.getName() << ", 그룹 인원수 : " << elem.getGroup_num() << ", 순번 : " << elem.getTurn()
			<< ", 도착시간 : " << elem.getHour() << ":" << elem.getMinute() << " " << elem.getAM_PM() << endl;
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

// node의 데이터를 비교해보기 - 이름 비교
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

// 특정 이름을 가진 Node를 지운다.
bool List::deleteNode(string m_name)
{
	if (search(m_name)) {
		// current를 지우면 된다.
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
	// 특정 data가 없으면 false를 리턴한다.
	return false;
}

// 특정 Node를 지운다.
bool List::deleteNode(Link nodes)
{
	// nodes를 지우면 된다.
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


// 2개의 node를 swap하는 함수
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
	
	// head와 tail에 관한 설정
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

// 2개의 node를 swap하는 함수
bool List::swapLinkedList(Link node1, Link node2)
{
	// 만약 두 노드가 같다면 return한다.
	if (node1 == node2) return true;

	// head와 tail에 관한 설정
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

	// 입력받은 linkedlist의 head가 없으면 어떤 동작도 하지 않고 함수 종료
	if (!input_linkedlist.first(input_head)) {

		return;
	}

//	cout << input_head.getName() << endl;		// 박민지
//	cout << input_linkedlist.current->elem.getName() << endl;	// 이소라

	// 입력받은 linkedlist의 head에 해당하는 Link를 할당받음
	link_input_head = input_linkedlist.current;
	// cout << "입력받은 linkedlist의 head는 " << link_input_head->elem.getName() << "입니다.\n";

	// 기존 linkedlist의 tail이 없을 경우 입력받은 linkedlist를 할당하고 함수 종료
	if (!this->last(old_tail)) {

		return;
	}
	
	link_old_tail = current;
	// cout << "기존 linkedlist의 tail은 " << link_old_tail->elem.getName() << "입니다.\n";

	// 기존 linkedlist의 tail에 있는 거를 input_linkedlist에 연결하고
	// linkedlist1의 tail에 해당하는 node를 linkedlist2로 변경한다.
	// 또한 linkedlist2의 head에 해당하는 node를 linkedlist1의 prev에 연결한다.
	link_old_tail->next = link_input_head;
	link_input_head->prev = link_old_tail;

	// linkedlist1의 tail은 linkedlist2의 tail로 변경
	input_linkedlist.last(input_tail);
	// cout << "입력된 input의 tail은 " << current->elem.getName() << "입니다\n";
	this->tail = input_linkedlist.current;

	// linkedlist2의 head는 linkedlist1의 head로 변경
	//input_linkedlist.first(input_head);
	input_linkedlist.head = head;

	// cout << "입력된 input의 head는 " << input_linkedlist.head->elem.getName() << "입니다\n";

	return;
}

void List::reverse()
{
	// head와 tail을 바꾼다.
	ListElementType elem;
	Link link_next;
	first(elem);	// current = head가 된다.
	head = tail;
	tail = current;

	// prev와 next를 바꾼다.
	bool notEmpty(first(elem));

	while (notEmpty) {
		link_next = current->next;
		current->next = current->prev;
		current->prev = link_next;

		// 다음 노드로 진출한뒤 계속 한다.
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
	//	cout << "current_link는 " << current_link->elem.getName() << endl;
		while(1) {
			current_link = current_link->next;
			if (current_link == NULL) break;
			//cout << "n번째 current link" << current_link->elem.getName() << endl;
			//cout << elem.getArr_time() << " " << current_link->elem.getArr_time() << endl;
			if (elem == current_link->elem) {
				next_link = current_link->next;
				deleteNode(current_link);
				if (next_link == NULL) break;

				current_link = next_link->prev;
				//cout << "삭제!" << endl;
			}
			//if (current_link == tail) break;
		}
		i++;
		this->first(elem);
		for (int j = 0; j < i; j++)
			notEmpty = this->next(elem);
	//	cout << "하나끝" << endl;
	}
}

void List::quicksort()
{
	// first와 last를 구해서 밑의 quicksort를 호출한다.
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

// index를 이용한 Quicksort
void List::quicksort(int first, int last)
{
	if (first >= last) return;
	int lastSmall(first), i;
	ListElementType elem;
	Link link_1, link_2;
	 
	for (i = first + 1; i <= last; i++) {
		
		// i 인덱스에 있는 노드를 뽑기
		this->first(elem);
		for (int j = 0; j < i; j++)
			this->next(elem);
		link_1 = current;

		// first 인덱스에 있는 노드를 뽑기
		this->first(elem);
		for (int j = 0; j < first; j++)
			this->next(elem);
		link_2 = current;

		// 값을 비교해서 first보다 크면 
		// lastsmall을 1 증가시킨 뒤 lastsmall과 i 인덱스에 있는 노드를 swap함
		if (link_1->elem.getArr_time() <= link_2->elem.getArr_time()) {
			++lastSmall;
			this->first(elem);
			for (int j = 0; j < lastSmall; j++)
				this->next(elem);
			link_2 = current;

			this->swapLinkedList(link_2, link_1);
		}
	}

	// 최종적으로, lastsmall과 first를 swap함.
	int split = lastSmall;

	// first에 해당하는 노드 찾기
	this->first(elem);
	for (int j = 0; j < first; j++)
		this->next(elem);
	link_1 = current;

	// lastsmall에 해당하는 노드 찾기
	this->first(elem);
	for (int j = 0; j < lastSmall; j++)
		this->next(elem);
	link_2 = current;

	this->swapLinkedList(link_1, link_2);

	// pivot(여기서는 split)을 중심으로 좌우 재귀호출
	quicksort(first, split - 1);
	quicksort(split + 1, last);
}

// node를 이용한 quicksort (List class에서, typedef Node *Link로 선언함)
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