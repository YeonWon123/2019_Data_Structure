#include "Customer.h"
#include "insertion_sort.h"
#include "Quicksort.h"
#include <stdlib.h>
#include <chrono>
using namespace std::chrono;

// �ɸ� �ð��� �����ϴ� �������� �׸��� ī����
int counter_i = 0;
int counter_q = 0;
long long timecheckers_insertionSort[9];
long long timecheckers_quickSort[9];

// size���� �����͸� insertionSort�� �����ϰ�, ���ĵ� ���� ����� �ش�.
// �ɸ� �ð��� ����� �ְ�, �ٽ� ���󺹱���Ų��.
void data_analysis_insertionSort(Customer data[], Customer data_original[], int size);

// size���� �����͸� quickSort�� �����ϰ�, ���ĵ� ���� ����� �ش�.
// �ɸ� �ð��� ����� �ְ�, �ٽ� ���󺹱���Ų��.
void data_analysis_quicksort(Customer data[], Customer data_original[], int size);

// ���� ȭ�鿡 ����� �ش�.
void data_print(Customer data[], int size);

// �����͸� ���������� �����ؼ� �����ִ� �Լ�
void data_analysis_print();

int main(void)
{
	// main�Լ����� 10���� ���� array�� ����
	// ���̸�, �׷� �ο���, ����, �����ð�
	// worst case : �̹� ������ �Ǿ� �ִ� ���
	Customer data_worst_case[10] = { 
		Customer("�̼Ҷ�", 3, 1, 1115),
		Customer("�ڹ���", 1, 2, 1130),
		Customer("������", 1, 3, 1136),
		Customer("�����", 2, 4, 1200),
		Customer("�̻��", 5, 5, 1214),
		Customer("������", 2, 7, 1217),
		Customer("����ȣ", 2, 6, 1236),
		Customer("������", 3, 8, 1526),
		Customer("�����", 4, 9, 1543),
		Customer("���ָ�", 3, 10, 1602),
		};

	//������ ���� ȭ�鿡 ������
	cout << "���� �� ������ 1. worst case�� ���(�̹� ���ĵǾ� �ִ� ���)" << endl;
	data_print(data_worst_case, 10);

	// ���� ����
	Customer data_original[10];
	for (int i = 0; i < 10; i++) {
		data_original[i] = data_worst_case[i];
	}

	// ������ ���翡 �����ִ� insertionSort�� �̿��Ѵ�.
	// 10���� ������ �� 4��, 7��, 10���� ����
	data_analysis_insertionSort(data_worst_case, data_original, 4);
	data_analysis_insertionSort(data_worst_case, data_original, 7);
	data_analysis_insertionSort(data_worst_case, data_original, 10);

	// ������ ���翡 �����ִ� quicksort�� �̿��Ѵ�.
	// 10���� ������ �� 4��, 7��, 10���� ����
	data_analysis_quicksort(data_worst_case, data_original, 4);
	data_analysis_quicksort(data_worst_case, data_original, 7);
	data_analysis_quicksort(data_worst_case, data_original, 10);

	// �ι�° �����͸� ����� ����
	// best case : �� ó�� ���� ��� �߰����� ���
	// ex : 8 1 3 2 6 5 7 4 12 9 11 10 14 13 15
	// ���̸�, �׷� �ο���, ����, �����ð�
	Customer data_best_case[15] = {
		Customer("������", 3, 8, 1526),
		Customer("�̼Ҷ�", 3, 1, 1115),
		Customer("������", 1, 3, 1136),
		Customer("�ڹ���", 1, 2, 1130),
		Customer("������", 2, 7, 1217),
		Customer("�̻��", 5, 5, 1214),
		Customer("����ȣ", 2, 6, 1236),
		Customer("�����", 2, 4, 1200),
		Customer("������", 3, 12, 1648),
		Customer("�����", 4, 9, 1543),
		Customer("����ȣ", 5, 11, 1620),
		Customer("���ָ�", 3, 10, 1602),
		Customer("�賲��", 1, 14, 1720),
		Customer("������", 2, 13, 1650),
		Customer("�̼���", 6, 15, 1800)
	};

	// ȭ�鿡 ������ ���� ȭ�鿡 ������
	cout << endl << endl << endl << "���� �� ������ 2. best case�� ���(�� ó�� ���� �߰����� ���)" << endl;
	data_print(data_best_case, 15);

	// ���� ����
	Customer data_original_2[15];
	for (int i = 0; i < 15; i++) {
		data_original_2[i] = data_best_case[i];
	}

	// ������ ���翡 �����ִ� insertionSort�� �̿��Ѵ�.
	// 15���� ������ �� 5��, 10��, 15���� ����
	data_analysis_insertionSort(data_best_case, data_original_2, 5);
	data_analysis_insertionSort(data_best_case, data_original_2, 10);
	data_analysis_insertionSort(data_best_case, data_original_2, 15);

	// ������ ���翡 �����ִ� quicksort�� �̿��ؼ� �����Ѵ�.
	// 15���� ������ �� 5��, 10��, 15���� ����
	data_analysis_quicksort(data_best_case, data_original_2, 5);
	data_analysis_quicksort(data_best_case, data_original_2, 10);
	data_analysis_quicksort(data_best_case, data_original_2, 15);
	
	// ����° ������ - �����͸� 100�� ����� ����
	// �� ���� average case�� �ش��Ѵ�!
	Customer bigdata[100];

	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		int r_v_0 = rand() % 100 + 1;
		int r_v_1 = rand() % 10 + 1;
		int r_v_2 = rand() % 100 + 1;
		int r_v_3 = rand() % 2400;
		// 60���� ���� ���� ����.
		while ((r_v_3 % 100) >= 60)
			r_v_3 = rand() % 2400;
		bigdata[i] = Customer("people", r_v_1, r_v_2, r_v_3);
	}

	cout << endl << endl << endl << "���� �� ������ 3. �������� ������ 100��(average case)" << endl;
	data_print(bigdata, 100);
		
	// ���� ����
	Customer data_original_3[100];
	for (int i = 0; i < 100; i++) {
		data_original_3[i] = bigdata[i];
	}
	   
	// ������ ���翡 �����ִ� insertionSort�� �̿��Ѵ�.
	// 100���� ������ �� 33��, 66��, 100���� ����
	data_analysis_insertionSort(bigdata, data_original_3, 33);
	data_analysis_insertionSort(bigdata, data_original_3, 66);
	data_analysis_insertionSort(bigdata, data_original_3, 100);

	// ������ ���翡 �����ִ� quicksort�� �̿��ؼ� �����Ѵ�.
	// 100���� ������ �� 33��, 66��, 100���� ����
	data_analysis_quicksort(bigdata, data_original_3, 33);
	data_analysis_quicksort(bigdata, data_original_3, 66);
	data_analysis_quicksort(bigdata, data_original_3, 100);

	// �м��� �����͵��� ������
	data_analysis_print();

	return 0;
}

void data_analysis_insertionSort(Customer data[], Customer data_original[], int size) {
	// ���Ǳ��翡 ���� �ִ� insertion sorting å�� �ִ� ���� �̿�
	// ����� int������ �������̹Ƿ�, �� Ŭ���� �����͸� ó���� �� �ֵ��� ������ Ÿ���� ������ �ش�.
	// ������ ������ �����ð����� �Ѵ�.
	// �񱳹��� operator overloading�� ����ϸ� �ȴ�.
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point endTime;
	nanoseconds currentSeconds;

	// size ���� ����
	startTime = high_resolution_clock::now();
	insertionSort(data, size);
	endTime = high_resolution_clock::now();
	currentSeconds = duration_cast<nanoseconds>(endTime - startTime);

	cout << endl << size << "�� insertionSort �Ϸ�!" << endl;
	cout << "insertionSort �ϴµ� �ɸ� �ð� : " << currentSeconds.count() << endl;
	timecheckers_insertionSort[counter_i] = currentSeconds.count();
	counter_i++;

	for (int i = 0; i < size; i++) {
		cout << "�� �̸� : " << data[i].getName() << ", �׷� �ο��� : " << data[i].getGroup_num()
			<< ", ���� : " << data[i].getTurn() << ", �����ð� : " << data[i].getArr_time() << endl;
	}

	// ���󺹱�
	for (int i = 0; i < size; i++) {
		data[i] = data_original[i];
	}
}

void data_analysis_quicksort(Customer data[], Customer data_original[], int size) {
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point endTime;
	nanoseconds currentSeconds;

	// size ���� ����
    startTime = high_resolution_clock::now();
	quicksort(data_original, 0, size-1);
	endTime = high_resolution_clock::now();
	currentSeconds = duration_cast<nanoseconds>(endTime - startTime);

	cout << endl << size << "�� quicksort �Ϸ�!" << endl;
	cout << "quicksort �ϴµ� �ɸ� �ð� : " << currentSeconds.count() << endl;
	timecheckers_quickSort[counter_q] = currentSeconds.count();
	counter_q++;

	for (int i = 0; i < size; i++) {
		cout << "�� �̸� : " << data[i].getName() << ", �׷� �ο��� : " << data[i].getGroup_num()
			<< ", ���� : " << data[i].getTurn() << ", �����ð� : " << data[i].getArr_time() << endl;
	}

	// ���󺹱�
	for (int i = 0; i < size; i++) {
		data[i] = data_original[i];
	}
}

// ���� ȭ�鿡 ������
void data_print(Customer data[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "�� �̸� : " << data[i].getName() << ", �׷� �ο��� : " << data[i].getGroup_num()
			<< ", ���� : " << data[i].getTurn() << ", �����ð� : " << data[i].getArr_time() << endl;
	}
}

// �����͸� ���������� �����ؼ� �����ִ� �Լ�
void data_analysis_print() {
	cout << "\n/****************************************************************/\n";
	cout << "/*********************** ���� ���� ******************************/\n";
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