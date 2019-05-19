#pragma once
#include "Customer.h"

// data field�� ù ��° ������ �� Ŭ������ ����Ѵ�.
typedef Customer ListElementType;

class List {
public:
	List();
	void PrintLinkedList();
	void PrintLinkedListBackward();
	void insert(const ListElementType & elem);
	void insertToTail(const ListElementType & elem);
	bool first(ListElementType & elem);
	bool next(ListElementType & elem);
	bool previous(ListElementType & elem);
	bool last(ListElementType & elem);
	bool search(string m_name);
	bool deleteNode(string m_name);
	bool swapLinkedList(string m_name1, string m_name2);
	void merge(List & input_linkedlist);
	void reverse();
	void unique();
	void quicksort();
private:
	struct Node; // declaration without definition
	typedef Node *Link;
	struct Node {
		ListElementType elem;
		Link next;
		Link prev;
	};
	Link head;
	Link tail;
	Link current;

public:
	// �����ε��Ǵ� �Լ���
	bool deleteNode(Link nodes);
	bool swapLinkedList(Link node1, Link node2);
	void quicksort(int first, int last);

};

