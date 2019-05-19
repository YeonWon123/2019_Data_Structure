#pragma once

typedef int ListElementType;
const int maxListSize = 1000;

class list
{
public:
	list();
	~list();
	void insert(const ListElementType & elem);
	bool first(ListElementType & elem);
	bool next(ListElementType & elem);
private:
	// implementation specific stuff here   
	ListElementType listArray[maxListSize];
	int numberOfElements; 	// 지금 몇 개 가 채워져 있는가
	int currentPosition;	// first와 next가 실행시 몇번째 위치를 가리키는지 나타낸다.

};

