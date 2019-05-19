#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>
#include<assert.h>
#include"measure.h"

using namespace std;
typedef measure ListElementType;


class List
{
private:


	struct Node;
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
	List();
	void Insert(const ListElementType &elem);  // head�� �ִ´�.
	void InsertToTail(const ListElementType &elem); // tail�� �ִ´�.
	bool first(ListElementType &elem);
	bool next(ListElementType &elem);
	bool last(ListElementType &elem);   //first�� �ݴ밳��
	bool previous(ListElementType &elem); // next�� �ݴ밳��
	void PrintLinkedList(ListElementType &elem);
	void PrintLinkedListBackward(ListElementType &elem);
	bool SwapLinkedList(string A, string B);
	int Search(string name);
	bool Delete(string name);
	void Merge(List &elem);
	void reverse();
	void unique();
	void quicksort( Link first, Link last);
	Link partition(Link first, Link last);
	Link partitino2(Link first, Link last);
	Link f();
	Link l();


	~List();


		
};

