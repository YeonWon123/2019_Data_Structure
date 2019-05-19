#include <iostream>
using namespace std;

#define SIZE 9

// desreasing order가 되게 구현
// 제일 작은 값을 맨 뒤로 가게 하기!
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

// Preorder : 이 함수는 입력값으로 정수형 배열과 맨 앞에서부터 어디까지 정렬할지를 양의 정수로 받음
// PostConditions : 이 함수가 끝나면 정렬할 범위 안에서, 맨 뒤에는 제일 작은 값이 오게 됨
// Return : void형이므로 Return값이 없으며 입력 인자로 받은 배열이 변하게 됨
void SelectionSort(int arr[], int a)
{
	int min(0), temp;
	
	// min값의 index를 찾음
	for (int i = 0; i < a; i++)
	{
		if (arr[min] > arr[i])
			min = i;
	}

	// swap하는 부분
	temp = arr[a - 1];
	arr[a - 1] = arr[min];
	arr[min] = temp;
}