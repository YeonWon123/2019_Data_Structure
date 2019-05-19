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
	// linkedlist가 아니므로 비워 놓는다. (사실상 필요가 없다.)
}

template < class queueElementType >
void
Queue < queueElementType >::enqueue(queueElementType e)
{
	// add e to the rear of the queue, advancing r to next position
	// cout << isFull() << endl;
	assert(!isFull());

	/*
	// 생성자가 f = 0이고 r = 0일 때, r을 증가시킨 후 Data를 넣음
	r = nextPos(r);
	elements[r] = e;
	*/

	// 생성자가 f = 0이고 r = 0일 때, Data를 넣고 r 증가
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
	// 생성자가 f = 0이고 r = 0일 때, f를 증가시킨 후 Data를 뽑음
	f = nextPos(f);
	return elements[f];
	*/
	// 생성자가 f = 0이고 r = 0일 때, Data를 뽑고 f 증가
	queueElementType e;
	e = elements[f]; // 데이터를 하나 뽑고
	f = nextPos(f);	 // f를 하나 증가
	return e;		 // 뽑은 데이터를 반환
}

template < class queueElementType >
queueElementType
Queue < queueElementType >::front()
{
	// return value of element at the front
	assert(!isEmpty());
	
	/*
	// 생성자가 f = 0이고 r = 0일 때, r이나 f을 증가시킨 후 Data를 넣거나 뽑은 경우
	return elements[nextPos(f)];
	*/

	// 생성자가 f = 0이고 r = 0일 때, Data를 넣거나 뽑고 r이나 f를 증가시킨 경우
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
	return bool(nextPos(r) == f); // f == r+1하면 안됨! (r = 0이고 f = n-1인 경우, 꽉 차도 성립하지 않음)
	// assert랑 충돌이 나는데, 왜 그런지 살펴보기!
	// 오류를 고쳐보자!
}