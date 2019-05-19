#include<iostream>
#include<stdlib.h> 
#include<time.h>
#include<chrono>
#include<ratio>
#include"measure.h"

std::chrono::high_resolution_clock;

typedef measure tock;
const int nsize = 10;
measure arr[nsize], arr2[nsize];  // 문제 1,2,3번에서 사용되는 배열 arr,  배열되기전 데이터 저장하기위한 배열 arr2
tock backup3[3], backup4[9], backup5[100];// 문제4번의 원래의 데이터를 보존하기 위한 배열 
tock backup6[3], backup7[9], backup8[100];// 문제 4번의 원래의 데이터 보존하기 위한 배열 클래스
int a[18]; // 문제 4번의 3개의 케이스의 함수실행 시간을 저장하는 배열


void clinetinfoout(measure arr[],int nsize);
//precondition: clinetinfo 함수가 먼저 실행 되야 한다.
//postcondition: 고객의 이름과 도착시간 그룹멤버수와 순번이 출력된다.

void backup(measure arr[], measure arr2[], int nsize);
//precondition:
//postcondition: arr에 있는 배열들의 정보를 arr2에  저장해둔다.


void DataSet(measure arr[], int n);
//precondition: 
//postcondition: 고객의 이름과  도착 시간 그룹 수가 랜덤으로 배정된다. 

int TimeMeasure1(void (*fp)(tock a[], int n),tock a[],int n);
//precondition: 
//postcondition: fp함수의  실행시간 측정
//return: insertino함수의 실행시간

int TimeMeasure2(void (*fp)(tock a[], int first, int last),tock a[], int first,int last);
//precondition:
//postcondition: fp함수의 실행시간 측정
//return: quicksort함수의 실행 시간

void Time(tock a[], int n,int arr[],int i);
//precondition: TimeMeasure1함수 , TimeMeasure2 함수
//postcondition: insertionsort와  quicksort함수 실행 시간이 측정된다(출력된다)
//               TimeMeasure1 리턴값이 arr[i]에 저장, TimeMeasure2 리턴값이 arr[i+1]에 저장된다  
void functionTime();
//precondition: worstcase, bestcase,averagecase에서 각각 3가지 경우의 함수실행시간이  a배열에 저장되있어야한다.
//postcondition: a배열에 저장되 있는  각 함수 실행 시간을 출력한다.




void InsertionNextItem(tock a[], int i);
void InsertionSort(tock a[], int n);

int partition(tock a[], int first, int last);
void quicksort(tock a[], int first, int last);
void swapElements(tock a[], int first, int last);


int main(void)
{
	cout << "정렬 하기 전 고객 리스트" << endl;
	DataSet(arr, nsize);
	clinetinfoout(arr, nsize);
	cout << endl << endl;

	backup(arr, arr2,nsize); // Insertionsort를 하기 전에 데이터를 백업해둔다.

	cout << "InsertionSort!!!!" << endl;
    InsertionSort(arr, nsize);
	clinetinfoout(arr, nsize);
	cout << endl << endl;

	cout << "정렬 하기 전 고객 리스트" << endl;
	clinetinfoout(arr2, nsize);
	cout << endl << endl;


	cout << endl << endl;
	cout << "quicksort!!!!!" << endl;  // 백업해 놓은 데이터로 quicksort를 구현한다.
	quicksort(arr2, 0, nsize-1);
	clinetinfoout(arr, nsize);

	cout << endl << endl;

	
	cout << "1. 데이터 개수가 3개일때----worst case" << endl << endl;
	
	tock arr3[3] = { tock("김명원",3,29,12,30,"PM"),tock("김구라",3,31,6,25,"PM"),
					  tock("김주원", 2, 37, 7, 20, "PM") };

	backup(arr3, backup3, 3); backup(arr3, backup6, 3);

	cout << "배열하기 전 데이터" << endl;
	clinetinfoout(arr3, 3); cout << endl;

	cout << "1개까지 배열   할 경우" << endl;
	Time(arr3, 1,a,0); cout << endl;   
    clinetinfoout(arr3, 3); cout << endl;

	cout << "2개까지 배열을 할 경우" << endl;
	Time(backup3, 2,a,2); cout << endl;
    clinetinfoout(backup3,3); cout << endl;

	cout << "3개     배열을 할 경우" << endl;
	Time(backup6, 3,a,4); cout << endl;
	clinetinfoout(backup6, 3); cout << endl;


	tock arr4[9] = { tock("김명원",3,29,5,30,"PM"),tock("김주원",3,45,3,20,"PM"),tock("김구라",3,44,1,20,"PM"),
				   tock("김나나",3,56,2,25,"AM"),tock("누누",2,33,4,40,"AM"),tock("룰루",1,56,6,45,"PM"),
				   tock("진",3,41,9,30,"PM"), tock("사자",1,11,7,40,"PM"),tock("호랭이",1,77,6,20,"PM") };
	

	backup(arr4, backup4, 9); backup(arr4, backup7, 9);

	cout << "2. 데이터 개수가 9개일때----best case" << endl << endl;
	cout << "배열하기 전 데이터" << endl;
	clinetinfoout(arr4, 9); cout << endl;

	cout << "3개까지 배열   할 경우" << endl;
	Time(arr4, 3,a,6); cout << endl;
	clinetinfoout(arr4, 9); cout << endl;

	cout << "6개까지 배열을 할 경우" << endl;
	Time(backup4, 6,a,8); cout << endl;
	clinetinfoout(backup4, 9); cout << endl;

	cout << "9개     배열을 할 경우" << endl;
	Time(backup7, 9,a,10); cout << endl;
	clinetinfoout(backup7, 9); cout << endl;


	tock arr5[100];
	DataSet(arr5, 100);
	backup(arr5, backup5,100); backup(arr5, backup8,100);
	cout << "3.데이터 개수가 100개 일때-average case" << endl << endl;
	cout << "배열하기 전 데이터" << endl;
	clinetinfoout(arr5, 100); cout << endl;

	cout << "33개까지 배열   할 경우" << endl;
	Time(arr5, 33,a,12); cout << endl;
	clinetinfoout(arr5, 100); cout << endl;

	cout << "66개까지 배열을 할 경우" << endl;
	Time(backup5, 66,a,14); cout << endl;
	clinetinfoout(backup5, 100); cout << endl;

	cout << "100개     배열을 할 경우" << endl;
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
		cout << "순번:" << arr[i].getnumber() << " ";
		cout << "고객 이름:" << arr[i].getclientname()<< " ";
		cout << "그룹 수:" << arr[i].getgroubnumber() << " ";
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
	string name = "로봇";

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
	cout << "insertionsort 함수실행시간:" << duration;
	
	return duration;
}


int TimeMeasure2(void (*fp)(tock a[], int first, int last),tock a[] , int first, int last)
{
	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();

	fp(a, first,last);

	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

	cout <<"quicksort 함수실행시간:"<< duration;
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

	cout << "-------------------------전체 정리---------------------------" << endl;
	cout << "1. 데이터 개수가 3개일때----worst case" << endl << endl;
	cout << "1개 배열할 경우: " << "Insertion sort:" << a[0] << " " << "quick sort:" << a[1] << endl;
	cout << "2개 배열할 경우: " << "Insertion sort:" << a[2] << " " << "quick sort:" << a[3] << endl;
	cout << "3개 배열할 경우: " << "Insertion sort:" << a[4] << " " << "quick sort:" << a[5] << endl;
	cout << endl << endl;

	cout << "2. 데이터 개수가 9개일때----best case" << endl << endl;
	cout << "3개 배열할 경우: " << "Insertion sort:" << a[6] << " " << "quick sort:" << a[7] << endl;
	cout << "6개 배열할 경우: " << "Insertion sort:" << a[8] << " " << "quick sort:" << a[9] << endl;
	cout << "9개 배열할 경우: " << "Insertion sort:" << a[10] << " " << "quick sort:" << a[11] << endl;
	cout << endl << endl;

	cout << "3. 데이터 개수가 100개일때----average case" << endl << endl;
	cout << "33개 배열할 경우: " << "Insertion sort:" << a[12] << " " << "quick sort:" << a[13] << endl;
	cout << "66개 배열할 경우: " << "Insertion sort:" << a[14] << " " << "quick sort:" << a[15] << endl;
	cout << "100개 배열할 경우: " << "Insertion sort:" << a[16] << " " << "quick sort:" << a[17] << endl;
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
