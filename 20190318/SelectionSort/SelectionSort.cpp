#include <iostream>
using namespace std;

#define SIZE 9

// desreasing order�� �ǰ� ����
// ���� ���� ���� �� �ڷ� ���� �ϱ�!
void SelectionSort(int arr[], int a);

int main(void)
{
	int arr[SIZE] = { 26, 54, 93, 17, 77, 31, 44, 55, 20 };

	for (int i = 0; i < SIZE-1; i++) {
		SelectionSort(arr, SIZE - i);
	}

	for(int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";

	return 0;
}

// Preorder : �� �Լ��� �Է°����� ������ �迭�� �� �տ������� ������ ���������� ���� ������ ����
// PostConditions : �� �Լ��� ������ ������ ���� �ȿ���, �� �ڿ��� ���� ���� ���� ���� ��
// Return : void���̹Ƿ� Return���� ������ �Է� ���ڷ� ���� �迭�� ���ϰ� ��
void SelectionSort(int arr[], int a)
{
	int min(0), temp;
	
	// min���� index�� ã��
	for (int i = 0; i < a; i++)
	{
		if (arr[min] > arr[i])
			min = i;
	}

	// swap�ϴ� �κ�
	temp = arr[a - 1];
	arr[a - 1] = arr[min];
	arr[min] = temp;
}