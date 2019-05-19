#pragma once
#include <string>
using namespace std;

class CPhone
{
public:
	CPhone();
	CPhone(int n_birthday, string str_name);
	~CPhone();

private:
	string m_str_name;
	int m_birthday;
};

