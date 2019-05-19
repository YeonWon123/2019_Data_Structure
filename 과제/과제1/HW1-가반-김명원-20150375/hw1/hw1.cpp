#include<iostream>
#include<stdlib.h> 
#include<time.h>
#include<chrono>
#include<ratio>
#include"measure.h"

std::chrono::high_resolution_clock;

typedef measure tock;
const int nsize = 10;
measure arr[nsize], arr2[nsize];  // ���� 1,2,3������ ���Ǵ� �迭 arr,  �迭�Ǳ��� ������ �����ϱ����� �迭 arr2
tock backup3[3], backup4[9], backup5[100];// ����4���� ������ �����͸� �����ϱ� ���� �迭 
tock backup6[3], backup7[9], backup8[100];// ���� 4���� ������ ������ �����ϱ� ���� �迭 Ŭ����
int a[18]; // ���� 4���� 3���� ���̽��� �Լ����� �ð��� �����ϴ� �迭


void clinetinfoout(measure arr[],int nsize);
//precondition: clinetinfo �Լ��� ���� ���� �Ǿ� �Ѵ�.
//postcondition: ���� �̸��� �����ð� �׷������� ������ ��µȴ�.

void backup(measure arr[], measure arr2[], int nsize);
//precondition:
//postcondition: arr�� �ִ� �迭���� ������ arr2��  �����صд�.


void DataSet(measure arr[], int n);
//precondition: 
//postcondition: ���� �̸���  ���� �ð� �׷� ���� �������� �����ȴ�. 

int TimeMeasure1(void (*fp)(tock a[], int n),tock a[],int n);
//precondition: 
//postcondition: fp�Լ���  ����ð� ����
//return: insertino�Լ��� ����ð�

int TimeMeasure2(void (*fp)(tock a[], int first, int last),tock a[], int first,int last);
//precondition:
//postcondition: fp�Լ��� ����ð� ����
//return: quicksort�Լ��� ���� �ð�

void Time(tock a[], int n,int arr[],int i);
//precondition: TimeMeasure1�Լ� , TimeMeasure2 �Լ�
//postcondition: insertionsort��  quicksort�Լ� ���� �ð��� �����ȴ�(��µȴ�)
//               TimeMeasure1 ���ϰ��� arr[i]�� ����, TimeMeasure2 ���ϰ��� arr[i+1]�� ����ȴ�  
void functionTime();
//precondition: worstcase, bestcase,averagecase���� ���� 3���� ����� �Լ�����ð���  a�迭�� ������־���Ѵ�.
//postcondition: a�迭�� ����� �ִ�  �� �Լ� ���� �ð��� ����Ѵ�.




void InsertionNextItem(tock a[], int i);
void InsertionSort(tock a[], int n);

int partition(tock a[], int first, int last);
void quicksort(tock a[], int first, int last);
void swapElements(tock a[], int first, int last);


int main(void)
{
	cout << "���� �ϱ� �� �� ����Ʈ" << endl;
	DataSet(arr, nsize);
	clinetinfoout(arr, nsize);
	cout << endl << endl;

	backup(arr, arr2,nsize); // Insertionsort�� �ϱ� ���� �����͸� ����صд�.

	cout << "InsertionSort!!!!" << endl;
    InsertionSort(arr, nsize);
	clinetinfoout(arr, nsize);
	cout << endl << endl;

	cout << "���� �ϱ� �� �� ����Ʈ" << endl;
	clinetinfoout(arr2, nsize);
	cout << endl << endl;


	cout << endl << endl;
	cout << "quicksort!!!!!" << endl;  // ����� ���� �����ͷ� quicksort�� �����Ѵ�.
	quicksort(arr2, 0, nsize-1);
	clinetinfoout(arr, nsize);

	cout << endl << endl;

	
	cout << "1. ������ ������ 3���϶�----worst case" << endl << endl;
	
	tock arr3[3] = { tock("����",3,29,12,30,"PM"),tock("�豸��",3,31,6,25,"PM"),
					  tock("���ֿ�", 2, 37, 7, 20, "PM") };

	backup(arr3, backup3, 3); backup(arr3, backup6, 3);

	cout << "�迭�ϱ� �� ������" << endl;
	clinetinfoout(arr3, 3); cout << endl;

	cout << "1������ �迭   �� ���" << endl;
	Time(arr3, 1,a,0); cout << endl;   
    clinetinfoout(arr3, 3); cout << endl;

	cout << "2������ �迭�� �� ���" << endl;
	Time(backup3, 2,a,2); cout << endl;
    clinetinfoout(backup3,3); cout << endl;

	cout << "3��     �迭�� �� ���" << endl;
	Time(backup6, 3,a,4); cout << endl;
	clinetinfoout(backup6, 3); cout << endl;


	tock arr4[9] = { tock("����",3,29,5,30,"PM"),tock("���ֿ�",3,45,3,20,"PM"),tock("�豸��",3,44,1,20,"PM"),
				   tock("�質��",3,56,2,25,"AM"),tock("����",2,33,4,40,"AM"),tock("���",1,56,6,45,"PM"),
				   tock("��",3,41,9,30,"PM"), tock("����",1,11,7,40,"PM"),tock("ȣ����",1,77,6,20,"PM") };
	

	backup(arr4, backup4, 9); backup(arr4, backup7, 9);

	cout << "2. ������ ������ 9���϶�----best case" << endl << endl;
	cout << "�迭�ϱ� �� ������" << endl;
	clinetinfoout(arr4, 9); cout << endl;

	cout << "3������ �迭   �� ���" << endl;
	Time(arr4, 3,a,6); cout << endl;
	clinetinfoout(arr4, 9); cout << endl;

	cout << "6������ �迭�� �� ���" << endl;
	Time(backup4, 6,a,8); cout << endl;
	clinetinfoout(backup4, 9); cout << endl;

	cout << "9��     �迭�� �� ���" << endl;
	Time(backup7, 9,a,10); cout << endl;
	clinetinfoout(backup7, 9); cout << endl;


	tock arr5[100];
	DataSet(arr5, 100);
	backup(arr5, backup5,100); backup(arr5, backup8,100);
	cout << "3.������ ������ 100�� �϶�-average case" << endl << endl;
	cout << "�迭�ϱ� �� ������" << endl;
	clinetinfoout(arr5, 100); cout << endl;

	cout << "33������ �迭   �� ���" << endl;
	Time(arr5, 33,a,12); cout << endl;
	clinetinfoout(arr5, 100); cout << endl;

	cout << "66������ �迭�� �� ���" << endl;
	Time(backup5, 66,a,14); cout << endl;
	clinetinfoout(backup5, 100); cout << endl;

	cout << "100��     �迭�� �� ���" << endl;
	Time(backup8, 100,a,16); cout << endl;
	clinetinfoout(backup8, 100); cout << endl;


	functionTime();
	

	system("pause");
	return 0;
}


void clinetinfoout(measure arr[],int nsize)
{
	for (int i = 0; i < nsize; i++)
	{
		//arr[i].setnumber(i+1);

		cout << "*************************************************" << endl;
		cout << "����:" << arr[i].getnumber() << " ";
		cout << "�� �̸�:" << arr[i].getclientname()<< " ";
		cout << "�׷� ��:" << arr[i].getgroubnumber() << " ";
	    arr[i].outtime();
		cout << "*************************************************";
		cout << endl;
	}

}

void backup(measure arr[], measure arr2[], int nsize)
{
	for (int i = 0; i < nsize; i++)
		arr2[i] = arr[i];
}

void DataSet(measure arr[], int n)
{
	srand(time(NULL));
	int object = 0;
	string m, name2, name3;
	string name = "�κ�";

	for (int i = 0; i < n; i++)
	{
		object = rand() % 2;
		if (object == 1)
			m = "AM";
		else
			m = "PM";
		
		for (int i = 1; i < n; i++)
		{
			name3 = to_string(i);  name2 = name + name3;

			arr[i].setclientname(name2);
		}
		arr[i].setgroubnumber(rand() % 10 + 1);
		arr[i].setnumber(rand() % 100 + 1);
		arr[i].sethour(rand() % 12 + 1);
		arr[i].setminute(rand() % 59);
		arr[i].setAMPM(m);


		if (arr[i].gethour() == 12)
			arr[i].setminutes(arr[i].getminute());
		else
			arr[i].setminutes( arr[i].gethour() * 60 + arr[i].getminute());
		

		if (arr[i].getAMPM() == "PM")
			arr[i].setminutes(arr[i].getminutes() + 60 * 12);
	}



}

int TimeMeasure1(void (*fp)(tock a[], int n),tock a[],int n)
{
	

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	fp(a, n);

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration =std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout << "insertionsort �Լ�����ð�:" << duration;
	
	return duration;
}


int TimeMeasure2(void (*fp)(tock a[], int first, int last),tock a[] , int first, int last)
{
	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();

	fp(a, first,last);

	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

	cout <<"quicksort �Լ�����ð�:"<< duration;
	return duration;
}

void Time(tock a[], int n,int arr[],int i)
{
	//DataSet(a, n);
	arr[i]=TimeMeasure1(InsertionSort, a, n);
	cout <<"    ";
	arr[i+1]=TimeMeasure2(quicksort, a,0,n-1);
	cout << endl;
}

void functionTime()
{

	cout << "-------------------------��ü ����---------------------------" << endl;
	cout << "1. ������ ������ 3���϶�----worst case" << endl << endl;
	cout << "1�� �迭�� ���: " << "Insertion sort:" << a[0] << " " << "quick sort:" << a[1] << endl;
	cout << "2�� �迭�� ���: " << "Insertion sort:" << a[2] << " " << "quick sort:" << a[3] << endl;
	cout << "3�� �迭�� ���: " << "Insertion sort:" << a[4] << " " << "quick sort:" << a[5] << endl;
	cout << endl << endl;

	cout << "2. ������ ������ 9���϶�----best case" << endl << endl;
	cout << "3�� �迭�� ���: " << "Insertion sort:" << a[6] << " " << "quick sort:" << a[7] << endl;
	cout << "6�� �迭�� ���: " << "Insertion sort:" << a[8] << " " << "quick sort:" << a[9] << endl;
	cout << "9�� �迭�� ���: " << "Insertion sort:" << a[10] << " " << "quick sort:" << a[11] << endl;
	cout << endl << endl;

	cout << "3. ������ ������ 100���϶�----average case" << endl << endl;
	cout << "33�� �迭�� ���: " << "Insertion sort:" << a[12] << " " << "quick sort:" << a[13] << endl;
	cout << "66�� �迭�� ���: " << "Insertion sort:" << a[14] << " " << "quick sort:" << a[15] << endl;
	cout << "100�� �迭�� ���: " << "Insertion sort:" << a[16] << " " << "quick sort:" << a[17] << endl;
	cout << endl << endl;


}

void InsertionNextItem(tock a[] ,int i)
{
	tock newItem(a[i]);  int insertPos(i);
	for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
	{
		a[insertPos] = a[insertPos - 1];
	}
	a[insertPos] = newItem;

}

void InsertionSort(tock a[], int n)
{
	int i;
	for (i = 1; i < n; i++)
		InsertionNextItem(a, i);
}

int partition(tock a[], int first, int last)
{
	int lastsmall = first; int i;

	for (i = first + 1; i <= last; i++)
	{
		if (a[i] <= a[first])
		{
			++lastsmall;
			swapElements(a, lastsmall, i);

		}
	}

	swapElements(a, first, lastsmall);
	return lastsmall;
}

void quicksort(tock a[], int first, int last)
{
	if (first >= last)
		return;

	int split = partition(a, first, last);
	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
}

void swapElements(tock a[], int first, int last)
{
	
	tock object = a[first];
	a[first] = a[last];
	a[last] = object;
}
