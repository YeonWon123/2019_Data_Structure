#include "Customer.h"

Customer::Customer()
{
}

Customer::Customer(string m_name, int m_group_num, int m_turn, int m_arr_time)
{
	name = m_name;
	group_num = m_group_num;
	turn = m_turn;
	arr_time = m_arr_time;
}

Customer::~Customer()
{
}

// get 함수
string Customer::getName()
{
	return name;
}


int Customer::getTurn()
{
	return turn;
}


int Customer::getGroup_num()
{
	return group_num;
}


int Customer::getArr_time()
{
	return arr_time;
}

// set 함수
void Customer::setName(string m_name)
{
	name = m_name;
}


void Customer::setArr_time(int m_arr_time)
{
	arr_time = m_arr_time;
}


void Customer::setTurn(int m_turn)
{
	turn = m_turn;
}


void Customer::setGroup_num(int m_group_num)
{
	group_num = m_group_num;
}

void Customer::readTime(bool & errorFlag)
{
	// The time must be formatted as <HH>:<MM><AMorPM>, where
	// <HH> is an int in the range 0 to 12, <MM> is an int in
	// the range 0 to 59, and <AMorPM> is either AM or PM.
	enum AM_PM { AM, PM } AM_or_PM;
	int hour, minute;
	const char delimiter = ':';

	// Assume that the format is bad -- once valid data is extracted,
	// reset errorFlag to false

	errorFlag = true;
	// formatted input -- fail if not an int
	if (!(cin >> hour))
		return;
	if (hour < 0 || hour > 12)
		return;

	char c;
	cin >> c;
	if (c != delimiter)
		return;
	if (!(cin >> minute)) // formatted input
		return;
	if (minute < 0 || minute > 59)
		return;

	cin >> c;
	if (c == 'A' || c == 'a')
		AM_or_PM = AM;
	else if (c == 'P' || c == 'p')
		AM_or_PM = PM;
	else
		return;
	cin >> c;
	if (c != 'M' && c != 'm')
		return;


	errorFlag = false;

	if (hour == 12)
		arr_time = minute;
	else
		arr_time = hour * 60 + minute;
	if (AM_or_PM == PM)
		arr_time += 60 * 12;

}

int Customer::subtractTimes(Customer t)
{
	return arr_time - t.arr_time;
}

void Customer::Addtime(int arrival_minutes, int future_time)
{
	// arrival_minutes에서 시간, 분, PM 추출
	int hour = arrival_minutes / 60;
	// 평균 대기 시간을 더해서 예측되는 진료시간 출력
	int minute = arrival_minutes - (arrival_minutes / 60) * 60 + future_time;
	while (minute >= 60) {
		hour++;
		minute = minute - 60;
	}
	if (hour > 12) {
		hour = hour - 12;
	}

	cout << "예측되는 진료시간은 약 " << hour << "시 " << minute << "분 입니다!";

}