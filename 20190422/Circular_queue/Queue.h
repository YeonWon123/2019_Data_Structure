// cx9-2.h

// Code Example 9-2: Header File for Queue

#ifndef __MB_CX9_2__
#define __MB_CX9_2__

#include <assert.h>
#include <iostream>
using namespace std;

const int maxQueue = 200;

template < class queueElementType >
class Queue {
public:
	Queue();
	~Queue();
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();
	bool isFull();
private:
	int f; // marks the front of the queue
	int r; // marks the rear of the queue
	queueElementType elements[maxQueue];
};

#endif

int nextPos(int p)
{
	if (p == maxQueue - 1) // at end of circle
		return 0;
	else
		return p + 1;
}

template < class queueElementType >
Queue < queueElementType >::Queue()
{
	// start both front and rear at 0
	f = 0;
	r = 0;
}

template < class queueElementType >
Queue < queueElementType >::~Queue()
{
	// linkedlist�� �ƴϹǷ� ��� ���´�. (��ǻ� �ʿ䰡 ����.)
}

template < class queueElementType >
void
Queue < queueElementType >::enqueue(queueElementType e)
{
	// add e to the rear of the queue, advancing r to next position
	// cout << isFull() << endl;
	assert(!isFull());

	/*
	// �����ڰ� f = 0�̰� r = 0�� ��, r�� ������Ų �� Data�� ����
	r = nextPos(r);
	elements[r] = e;
	*/

	// �����ڰ� f = 0�̰� r = 0�� ��, Data�� �ְ� r ����
	elements[r] = e;
	r = nextPos(r);
}

template < class queueElementType >
queueElementType
Queue < queueElementType >::dequeue()
{
	// advance front of queue, return value of element at the front
	assert(!isEmpty());
	/*
	// �����ڰ� f = 0�̰� r = 0�� ��, f�� ������Ų �� Data�� ����
	f = nextPos(f);
	return elements[f];
	*/
	// �����ڰ� f = 0�̰� r = 0�� ��, Data�� �̰� f ����
	queueElementType e;
	e = elements[f]; // �����͸� �ϳ� �̰�
	f = nextPos(f);	 // f�� �ϳ� ����
	return e;		 // ���� �����͸� ��ȯ
}

template < class queueElementType >
queueElementType
Queue < queueElementType >::front()
{
	// return value of element at the front
	assert(!isEmpty());
	
	/*
	// �����ڰ� f = 0�̰� r = 0�� ��, r�̳� f�� ������Ų �� Data�� �ְų� ���� ���
	return elements[nextPos(f)];
	*/

	// �����ڰ� f = 0�̰� r = 0�� ��, Data�� �ְų� �̰� r�̳� f�� ������Ų ���
	return elements[f];
}

template < class queueElementType >
bool
Queue < queueElementType >::isEmpty()
{
	// return true if the queue is empty, that is,
	// if front is the same as rear
	return bool(f == r);
}

template < class queueElementType >
bool
Queue < queueElementType >::isFull()
{
	// return true if the queue is empty, that is,
	// if front is the same as rear
	return bool(nextPos(r) == f); // f == r+1�ϸ� �ȵ�! (r = 0�̰� f = n-1�� ���, �� ���� �������� ����)
	// assert�� �浹�� ���µ�, �� �׷��� ���캸��!
	// ������ ���ĺ���!
}