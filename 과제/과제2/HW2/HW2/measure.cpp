#include "measure.h"



measure::measure()
{
}

measure::measure(string name, int groub, int NUmber, int h, int m, string AP)
{
	clientname = name;
	groubnumber = groub;
	number = NUmber;
	hour = h;
	minute = m;
	AM_PM = AP;

	if (hour == 12)
		minutes = minute;
	else
		minutes = hour * 60 + minute;

	if (AM_PM == "PM")
		minutes += 60 * 12;
}


measure::~measure()
{
}



void measure::outtime()
{
	cout <<"µµÂø½Ã°£:"<< hour << ":" << minute << AM_PM << endl;
}

int measure::getgroubnumber()const
{

	return groubnumber;
}

void measure::setgroubnumber(int groubnumber2)
{
	groubnumber = groubnumber2;
}

int measure::getnumber()const
{
	return number;
}

void measure::setnumber(int number2)
{
	number = number2;
}

string measure::getclientname()const
{
	return clientname;
}

void measure::setclientname(string name)
{
	clientname = name;
}

int measure::gethour() const
{
	return hour;
}

void measure::sethour(int hour2)
{
	hour = hour2;
}

int measure::getminute() const
{
	return minute;
}

void measure::setminute(int minute2)
{
	minute = minute2;
}

string measure::getAMPM() const
{
	return AM_PM;
}

void measure::setAMPM(string M)
{
	AM_PM = M;
}

int measure::getminutes() const
{
	return minutes;
}

void measure::setminutes(int minute)
{
	minutes = minute;
}



const measure measure::operator=(const measure & amount2) 
{

	 clientname = amount2.clientname;	
	 groubnumber = amount2.groubnumber;
	 number = amount2.number;

	 minutes = amount2.minutes;
	 hour = amount2.hour;
	 minute = amount2.minute;
	 AM_PM = amount2.AM_PM;


	return *this;
}

bool measure::operator<(const measure & amount2)
{
	return (minutes<amount2.minutes);
}

bool measure::operator<=(const measure & amount2)
{
	return (minutes<=amount2.minutes);
}

bool measure::operator==(const measure & amount2)
{   
	if (clientname == amount2.clientname &&  hour == amount2.hour && minute == amount2.minute
		&&AM_PM == amount2.AM_PM)
		return true;
	else
		return false;
}


