#include "list.h"
#include <assert.h>

// ������ ���� �ʱ�ȭ
list::list()
{
	// initialize to an empty list
	numberOfElements = 0;
	currentPosition = -1; // ����! currentPosition�� -1�� �����Ѵ�.
			 // �� ������ �ѹ��� first�� ���� ���� ���� �ֱ� ����
}

list::~list()
{
}

void list::insert(const ListElementType & elem)
{
	assert(numberOfElements < maxListSize);
	listArray[numberOfElements] = elem; // ����ִ� ù��° index
	numberOfElements++;
}

bool list::first(ListElementType & elem)
{
	if (numberOfElements == 0) // �����Ͱ� ���� ���
		return false;
	else {
		currentPosition = 0;
		elem = listArray[currentPosition];
		return true;
	}
}

bool list::next(ListElementType & elem)
{
	// with proper use, currentPosition should always be
	// greater than or equal to zero
	assert(currentPosition >= 0); // ���� ������ ������ first�� �ѹ� �߱��� ���� ����
	if (currentPosition >= numberOfElements - 1) // ���ٰ� �ص� �ȴ�
		return false;
	else {
		currentPosition++;
		elem = listArray[currentPosition];
		return true;
	}
}
