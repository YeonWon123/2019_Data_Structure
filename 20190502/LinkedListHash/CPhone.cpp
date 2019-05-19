#include "CPhone.h"



CPhone::CPhone()
{
}

CPhone::CPhone(int n_birthday, string str_name)
{
	m_birthday = n_birthday;
	m_str_name = str_name;
}


CPhone::~CPhone()
{
}


string CPhone::getName()
{
	// TODO: 여기에 구현 코드 추가.
	return m_str_name;
}
