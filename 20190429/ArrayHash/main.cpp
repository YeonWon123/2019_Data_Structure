#include "Table.h"
#include "CPhone.h"

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
	T2.insert(19960429, CPhone(19960429, "Ã¶¼ö"));
	T2.insert(19960711, CPhone(19960711, "¿µÈñ"));
	T2.insert(19970101, CPhone(19970101, "¼öÁö"));
	T2.dump();
}