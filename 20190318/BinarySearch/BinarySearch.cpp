#include <iostream>
using namespace std;

#define SIZE 10

int arr[SIZE] = { -1,1,2,3,4,5,6,7,8,9 };
int BinarySearch(int start, int end, int target);

int main(void)
{
	int target;
	cout << "배열에서 찾을 정수를 입력하세요: ";
	cin >> target;

	int location;
	location = BinarySearch(1, SIZE, target);

	if (location == 0) cout << "찾지 못했습니다!\n";
	else cout << arr[location] << "가 있습니다!\n";

	return 0;
}

int BinarySearch(int start, int end, int target)
{
	int mid;

	if (start > end) return 0;
	else
	{
		mid = (start + end) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			return BinarySearch(start, mid - 1, target);
		else // if (arr[mid] < target)
			return BinarySearch(mid + 1, end, target);
	}
}