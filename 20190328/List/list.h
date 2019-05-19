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
	int numberOfElements; 	// ���� �� �� �� ä���� �ִ°�
	int currentPosition;	// first�� next�� ����� ���° ��ġ�� ����Ű���� ��Ÿ����.

};

