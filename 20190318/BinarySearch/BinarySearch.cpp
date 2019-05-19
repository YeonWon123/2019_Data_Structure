#include <iostream>
using namespace std;

#define SIZE 10

int arr[SIZE] = { -1,1,2,3,4,5,6,7,8,9 };
int BinarySearch(int start, int end, int target);

int main(void)
{
	int target;
	cout << "�迭���� ã�� ������ �Է��ϼ���: ";
	cin >> target;

	int location;
	location = BinarySearch(1, SIZE, target);

	if (location == 0) cout << "ã�� ���߽��ϴ�!\n";
	else cout << arr[location] << "�� �ֽ��ϴ�!\n";

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