#include "Table_template.h"
#include "CPhone.h"
#include <cmath>

int stringToInt(string strName);

int main(void)
{
	Table<int, int> T;
	T.insert(19960429, 19960429); // 5
	T.insert(19960507, 19960507); // 6
	T.insert(19950629, 19960629); // 7
	T.insert(19970711, 19960711); // 2
	T.insert(19980321, 19980321); // 9
	T.insert(19951228, 19951228); // 0
	T.insert(19970101, 19970101); // 8
	T.dump();

	T.deleteKey(19970711); // 2
	T.deleteKey(19970101); // 8
	T.dump();

	T.insert(19970623, 19970623); // 2
	T.dump();

	Table<int, CPhone> T2;
	CPhone A(19960429, "Charise");
	CPhone B(19960711, "Bob");
	CPhone C(19970101, "Nate");
	CPhone D(19970101, "nATe");
	T2.insert(19960429, A);
	T2.insert(19960711, B);
	T2.insert(19970101, C);
	T2.insert(19970101, D);
	T2.dump();

	Table<int, CPhone> T3;
	T3.insert(stringToInt(A.getName()), A);
	T3.insert(stringToInt(B.getName()), B);
	T3.insert(stringToInt(C.getName()), C);
	T3.insert(stringToInt(D.getName()), D);
	T3.dump();

}

// 문자를 숫자로 바꾸는 함수
int stringToInt(string strName) {
	int nLength = strName.length();
	int nSum = 0;
	for (int i = 0; i < nLength; i++) {
		nSum += strName.at(i)* pow(10,i); //특정 번째의 char가 나온다.
	}
	return nSum;
}


