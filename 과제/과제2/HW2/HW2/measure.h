#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
class measure
{
public:
	measure();
	measure(string name, int groub, int NUmber, int h, int m, string AP);
	~measure();
	

	void outtime();
	//precondition: 멤버변수의 hour,minute,AM_PM 값이 넣어져 있어야 한다.
	//postcondition: 고객이 도착한 시간을 출력해준다.

	int getgroubnumber()const; // 그룹인원수를 출력해준다
	void setgroubnumber(int groubnumber2); // 그룹인원 수를  멤버변수 groubnumber에 넣어준다.

	int getnumber()const; // 순번 수를 출력해준다
	void setnumber(int number2);// 순번 수를 멤버변수 number에 넣어준다.

	string getclientname()const; // 고객 이름을  출력한다.
	void setclientname(string name);// 고객 이름을 멤버변수 clientname에  넣어준다. 

	int gethour()const; // 도착시간의  시를 출력한다.
	void sethour(int hour2);// 도착시간의 시를 set해준다.

	int getminute()const;// 도착시간의 분을 출력한다.
	void setminute(int minute2);// 도착시간의 분을 set해준다.
	
	string getAMPM()const;// 도착시간의 오후 오전을 출력한다.
	void setAMPM(string M);// 도착시간의 오후 오전을 set해준다.

	int getminutes()const; // 도착시간을 분으로 환산한 숫자를 출력
	void setminutes(int minute);// minutes의 set함수

	const measure operator = ( const measure &amount2); // = 연산자를 오버로딩 한다.
	//precondition:amount2와  자신의 객체에 멤버변수 값들이 입력되 있어야 한다.
	//postcondition: 자신의 객체의 멤버변수들에  amount2객체의 멤버변수들의 값이 입력된다.

	 bool  operator < (const measure &amount2);
	 //precondition: amount2객체와 자신의 객체에  minutes 값이 입력되있어야 한다.
	 //Postcondition: 
	 //return: amount2 클래스의 minutes가 더크면 1, 작으면 0을 반환한다.
	 //1을 반환 했을때 : amount2가 더 늦게 도착했다. 0을 반환 했을때:amount2가 더 일찍 도착했다.

	 bool operator <= (const measure &amount2);
	  //precondition: amount2객체와 자신의 객체에 minutes 값이  입력되있어야 한다.
	  //postcondition: 
	 //return:amount2 클래스의 minutes가 더 크거나 같으면 1, 아니면 0을 반환한다.
	 //1을 반환 했을 때: amount2가 더 늦게 도착하거나 동시도착.  0을 반환 했을때:amount2가 더 일찍 도착했다.


	 bool operator ==(const measure &amount2);



private: string clientname;  // 고객이름
		 int groubnumber;   // 그룹 수
		 int number;// 순번
		 int minutes; // 도착시간을 분으로 환산

		 int hour;  // 입력한 시간의 시
		 int minute;// 입력한 시간의 분
		 string AM_PM; // am or pm
		 

};

