#include "list.h"
#include <assert.h>

// 생성자 변수 초기화
list::list()
{
	// initialize to an empty list
	numberOfElements = 0;
	currentPosition = -1; // 주의! currentPosition을 -1로 유지한다.
			 // 그 이유는 한번도 first를 하지 않을 수도 있기 때문
}

list::~list()
{
}

void list::insert(const ListElementType & elem)
{
	assert(numberOfElements < maxListSize);
	listArray[numberOfElements] = elem; // 비어있는 첫번째 index
	numberOfElements++;
}

bool list::first(ListElementType & elem)
{
	if (numberOfElements == 0) // 데이터가 없을 경우
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
	assert(currentPosition >= 0); // 양의 정수가 나오면 first를 한번 했구나 생각 가능
	if (currentPosition >= numberOfElements - 1) // 같다고 해도 된다
		return false;
	else {
		currentPosition++;
		elem = listArray[currentPosition];
		return true;
	}
}
