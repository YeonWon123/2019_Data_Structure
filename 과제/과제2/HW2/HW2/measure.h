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
	//precondition: ��������� hour,minute,AM_PM ���� �־��� �־�� �Ѵ�.
	//postcondition: ���� ������ �ð��� ������ش�.

	int getgroubnumber()const; // �׷��ο����� ������ش�
	void setgroubnumber(int groubnumber2); // �׷��ο� ����  ������� groubnumber�� �־��ش�.

	int getnumber()const; // ���� ���� ������ش�
	void setnumber(int number2);// ���� ���� ������� number�� �־��ش�.

	string getclientname()const; // �� �̸���  ����Ѵ�.
	void setclientname(string name);// �� �̸��� ������� clientname��  �־��ش�. 

	int gethour()const; // �����ð���  �ø� ����Ѵ�.
	void sethour(int hour2);// �����ð��� �ø� set���ش�.

	int getminute()const;// �����ð��� ���� ����Ѵ�.
	void setminute(int minute2);// �����ð��� ���� set���ش�.
	
	string getAMPM()const;// �����ð��� ���� ������ ����Ѵ�.
	void setAMPM(string M);// �����ð��� ���� ������ set���ش�.

	int getminutes()const; // �����ð��� ������ ȯ���� ���ڸ� ���
	void setminutes(int minute);// minutes�� set�Լ�

	const measure operator = ( const measure &amount2); // = �����ڸ� �����ε� �Ѵ�.
	//precondition:amount2��  �ڽ��� ��ü�� ������� ������ �Էµ� �־�� �Ѵ�.
	//postcondition: �ڽ��� ��ü�� ��������鿡  amount2��ü�� ����������� ���� �Էµȴ�.

	 bool  operator < (const measure &amount2);
	 //precondition: amount2��ü�� �ڽ��� ��ü��  minutes ���� �Էµ��־�� �Ѵ�.
	 //Postcondition: 
	 //return: amount2 Ŭ������ minutes�� ��ũ�� 1, ������ 0�� ��ȯ�Ѵ�.
	 //1�� ��ȯ ������ : amount2�� �� �ʰ� �����ߴ�. 0�� ��ȯ ������:amount2�� �� ���� �����ߴ�.

	 bool operator <= (const measure &amount2);
	  //precondition: amount2��ü�� �ڽ��� ��ü�� minutes ����  �Էµ��־�� �Ѵ�.
	  //postcondition: 
	 //return:amount2 Ŭ������ minutes�� �� ũ�ų� ������ 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	 //1�� ��ȯ ���� ��: amount2�� �� �ʰ� �����ϰų� ���õ���.  0�� ��ȯ ������:amount2�� �� ���� �����ߴ�.


	 bool operator ==(const measure &amount2);



private: string clientname;  // ���̸�
		 int groubnumber;   // �׷� ��
		 int number;// ����
		 int minutes; // �����ð��� ������ ȯ��

		 int hour;  // �Է��� �ð��� ��
		 int minute;// �Է��� �ð��� ��
		 string AM_PM; // am or pm
		 

};

