#include "Customer.h"
#include "insertion_sort.h"
#include "Quicksort.h"
#include <stdlib.h>
#include <chrono>
using namespace std::chrono;

// 걸린 시간을 보관하는 전역변수 그리고 카운터
int counter_i = 0;
int counter_q = 0;
long long timecheckers_insertionSort[9];
long long timecheckers_quickSort[9];

// size개의 데이터를 insertionSort로 정렬하고, 정렬된 값을 출력해 준다.
// 걸린 시간도 출력해 주고, 다시 원상복구시킨다.
void data_analysis_insertionSort(Customer data[], Customer data_original[], int size);

// size개의 데이터를 quickSort로 정렬하고, 정렬된 값을 출력해 준다.
// 걸린 시간도 출력해 주고, 다시 원상복구시킨다.
void data_analysis_quicksort(Customer data[], Customer data_original[], int size);

// 고객을 화면에 출력해 준다.
void data_print(Customer data[], int size);

// 데이터를 최종적으로 정리해서 보여주는 함수
void data_analysis_print();

int main(void)
{
	// main함수에서 10명의 고객을 array로 생성
	// 고객이름, 그룹 인원수, 순번, 도착시간
	// worst case : 이미 정렬이 되어 있는 경우
	Customer data_worst_case[10] = { 
		Customer("이소라", 3, 1, 1115),
		Customer("박민지", 1, 2, 1130),
		Customer("조유정", 1, 3, 1136),
		Customer("김상진", 2, 4, 1200),
		Customer("이상록", 5, 5, 1214),
		Customer("이진서", 2, 7, 1217),
		Customer("이주호", 2, 6, 1236),
		Customer("강산해", 3, 8, 1526),
		Customer("남상민", 4, 9, 1543),
		Customer("진주리", 3, 10, 1602),
		};

	//생성된 고객을 화면에 보여줌
	cout << "정렬 전 데이터 1. worst case인 경우(이미 정렬되어 있는 경우)" << endl;
	data_print(data_worst_case, 10);

	// 원본 저장
	Customer data_original[10];
	for (int i = 0; i < 10; i++) {
		data_original[i] = data_worst_case[i];
	}

	// 정렬을 교재에 나와있는 insertionSort를 이용한다.
	// 10개의 데이터 중 4개, 7개, 10개를 정렬
	data_analysis_insertionSort(data_worst_case, data_original, 4);
	data_analysis_insertionSort(data_worst_case, data_original, 7);
	data_analysis_insertionSort(data_worst_case, data_original, 10);

	// 정렬을 교재에 나와있는 quicksort를 이용한다.
	// 10개의 데이터 중 4개, 7개, 10개를 정렬
	data_analysis_quicksort(data_worst_case, data_original, 4);
	data_analysis_quicksort(data_worst_case, data_original, 7);
	data_analysis_quicksort(data_worst_case, data_original, 10);

	// 두번째 데이터를 만들어 보자
	// best case : 맨 처음 값이 계속 중간값인 경우
	// ex : 8 1 3 2 6 5 7 4 12 9 11 10 14 13 15
	// 고객이름, 그룹 인원수, 순번, 도착시간
	Customer data_best_case[15] = {
		Customer("강산해", 3, 8, 1526),
		Customer("이소라", 3, 1, 1115),
		Customer("조유정", 1, 3, 1136),
		Customer("박민지", 1, 2, 1130),
		Customer("이진서", 2, 7, 1217),
		Customer("이상록", 5, 5, 1214),
		Customer("이주호", 2, 6, 1236),
		Customer("김상진", 2, 4, 1200),
		Customer("남윤원", 3, 12, 1648),
		Customer("남상민", 4, 9, 1543),
		Customer("나상호", 5, 11, 1620),
		Customer("진주리", 3, 10, 1602),
		Customer("김남수", 1, 14, 1720),
		Customer("오수경", 2, 13, 1650),
		Customer("이수림", 6, 15, 1800)
	};

	// 화면에 생성된 고객을 화면에 보여줌
	cout << endl << endl << endl << "정렬 전 데이터 2. best case인 경우(맨 처음 값이 중간값인 경우)" << endl;
	data_print(data_best_case, 15);

	// 원본 저장
	Customer data_original_2[15];
	for (int i = 0; i < 15; i++) {
		data_original_2[i] = data_best_case[i];
	}

	// 정렬을 교재에 나와있는 insertionSort를 이용한다.
	// 15개의 데이터 중 5개, 10개, 15개를 정렬
	data_analysis_insertionSort(data_best_case, data_original_2, 5);
	data_analysis_insertionSort(data_best_case, data_original_2, 10);
	data_analysis_insertionSort(data_best_case, data_original_2, 15);

	// 정렬을 교재에 나와있는 quicksort를 이용해서 정렬한다.
	// 15개의 데이터 중 5개, 10개, 15개를 정렬
	data_analysis_quicksort(data_best_case, data_original_2, 5);
	data_analysis_quicksort(data_best_case, data_original_2, 10);
	data_analysis_quicksort(data_best_case, data_original_2, 15);
	
	// 세번째 데이터 - 데이터를 100개 만들어 보자
	// 이 경우는 average case에 해당한다!
	Customer bigdata[100];

	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		int r_v_0 = rand() % 100 + 1;
		int r_v_1 = rand() % 10 + 1;
		int r_v_2 = rand() % 100 + 1;
		int r_v_3 = rand() % 2400;
		// 60분을 넘을 수는 없다.
		while ((r_v_3 % 100) >= 60)
			r_v_3 = rand() % 2400;
		bigdata[i] = Customer("people", r_v_1, r_v_2, r_v_3);
	}

	cout << endl << endl << endl << "정렬 전 데이터 3. 데이터의 개수가 100개(average case)" << endl;
	data_print(bigdata, 100);
		
	// 원본 저장
	Customer data_original_3[100];
	for (int i = 0; i < 100; i++) {
		data_original_3[i] = bigdata[i];
	}
	   
	// 정렬을 교재에 나와있는 insertionSort를 이용한다.
	// 100개의 데이터 중 33개, 66개, 100개를 정렬
	data_analysis_insertionSort(bigdata, data_original_3, 33);
	data_analysis_insertionSort(bigdata, data_original_3, 66);
	data_analysis_insertionSort(bigdata, data_original_3, 100);

	// 정렬을 교재에 나와있는 quicksort를 이용해서 정렬한다.
	// 100개의 데이터 중 33개, 66개, 100개를 정렬
	data_analysis_quicksort(bigdata, data_original_3, 33);
	data_analysis_quicksort(bigdata, data_original_3, 66);
	data_analysis_quicksort(bigdata, data_original_3, 100);

	// 분석된 데이터들을 보여줌
	data_analysis_print();

	return 0;
}

void data_analysis_insertionSort(Customer data[], Customer data_original[], int size) {
	// 강의교재에 나와 있는 insertion sorting 책에 있는 내용 이용
	// 교재는 int형식의 데이터이므로, 고객 클래스 데이터를 처리할 수 있도록 데이터 타입을 변경해 준다.
	// 정렬의 기준은 도착시간으로 한다.
	// 비교문은 operator overloading을 사용하면 된다.
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point endTime;
	nanoseconds currentSeconds;

	// size 개를 정렬
	startTime = high_resolution_clock::now();
	insertionSort(data, size);
	endTime = high_resolution_clock::now();
	currentSeconds = duration_cast<nanoseconds>(endTime - startTime);

	cout << endl << size << "개 insertionSort 완료!" << endl;
	cout << "insertionSort 하는데 걸린 시간 : " << currentSeconds.count() << endl;
	timecheckers_insertionSort[counter_i] = currentSeconds.count();
	counter_i++;

	for (int i = 0; i < size; i++) {
		cout << "고객 이름 : " << data[i].getName() << ", 그룹 인원수 : " << data[i].getGroup_num()
			<< ", 순번 : " << data[i].getTurn() << ", 도착시간 : " << data[i].getArr_time() << endl;
	}

	// 원상복귀
	for (int i = 0; i < size; i++) {
		data[i] = data_original[i];
	}
}

void data_analysis_quicksort(Customer data[], Customer data_original[], int size) {
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point endTime;
	nanoseconds currentSeconds;

	// size 개를 정렬
    startTime = high_resolution_clock::now();
	quicksort(data_original, 0, size-1);
	endTime = high_resolution_clock::now();
	currentSeconds = duration_cast<nanoseconds>(endTime - startTime);

	cout << endl << size << "개 quicksort 완료!" << endl;
	cout << "quicksort 하는데 걸린 시간 : " << currentSeconds.count() << endl;
	timecheckers_quickSort[counter_q] = currentSeconds.count();
	counter_q++;

	for (int i = 0; i < size; i++) {
		cout << "고객 이름 : " << data[i].getName() << ", 그룹 인원수 : " << data[i].getGroup_num()
			<< ", 순번 : " << data[i].getTurn() << ", 도착시간 : " << data[i].getArr_time() << endl;
	}

	// 원상복귀
	for (int i = 0; i < size; i++) {
		data[i] = data_original[i];
	}
}

// 고객을 화면에 보여줌
void data_print(Customer data[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "고객 이름 : " << data[i].getName() << ", 그룹 인원수 : " << data[i].getGroup_num()
			<< ", 순번 : " << data[i].getTurn() << ", 도착시간 : " << data[i].getArr_time() << endl;
	}
}

// 데이터를 최종적으로 정리해서 보여주는 함수
void data_analysis_print() {
	cout << "\n/****************************************************************/\n";
	cout << "/*********************** 최종 정리 ******************************/\n";
	cout << "/****************************************************************/\n\n";
	cout << "1. data : quicksort's worst case...\n";
	cout << "data size : 4, 7, 10\n\n";
	cout << "1-1. Insertion Sort\n";
	for (int i = 0; i < 3; i++)
		cout << timecheckers_insertionSort[i] << "ns ";
	cout << "\n\n";

	cout << "1-2. Quick Sort\n";
	for (int i = 0; i < 3; i++)
		cout << timecheckers_quickSort[i] << "ns ";
	cout << "\n\n\n";

	cout << "2. data : quicksort's best case...\n";
	cout << "data size : 5, 10, 15\n\n";
	cout << "2-1. Insertion Sort\n";
	for (int i = 3; i < 6; i++)
		cout << timecheckers_insertionSort[i] << "ns ";
	cout << "\n\n";

	cout << "2-2. Quick Sort\n";
	for (int i = 3; i < 6; i++)
		cout << timecheckers_quickSort[i] << "ns ";
	cout << "\n\n\n";

	cout << "3. data : quicksort's average case...\n";
	cout << "data size : 33, 66, 100\n\n";
	cout << "3-1. Insertion Sort\n";
	for (int i = 6; i < 9; i++)
		cout << timecheckers_insertionSort[i] << "ns ";
	cout << "\n\n";

	cout << "3-2. Quick Sort\n";
	for (int i = 6; i < 9; i++)
		cout << timecheckers_quickSort[i] << "ns ";
	cout << "\n\n\n";
}