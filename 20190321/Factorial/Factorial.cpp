#include <iostream>
using namespace std;

// 함수 원형
int factorial(int n);
int nCombination(int n, int k);
int factorial_loop(int n);
int choose(int n, int k);

int counts = 0;

int main(void)
{
	int n, k;
	cout << "두 정수를 입력하세요: ";
	cin >> n >> k;
	// cout << input << "의 팩토리얼 : " << factorial(input);
	// cout << n << "C" << k << " = " << nCombination(n, k) << endl;

	cout << n << "C" << k << " = " << choose(n, k) << endl;
	cout << "연산의 횟수 : " << counts << "\n";
	return 0;
}

// recursion for Combination
int choose(int n, int k)
{
	counts++;
	if (k == 1)
		return n;
	else if (n == k)
		return 1;
	else // recursive case: n>k and k>1
		return choose(n - 1, k - 1) + choose(n - 1, k);
}

// loop
int nCombination(int n, int k)
{
	int n_fac;
	int k_fac;
	int n_kfac;

	n_fac = factorial_loop(n);
	k_fac = factorial_loop(k);
	n_kfac = factorial_loop(n - k);

	return n_fac / k_fac / n_kfac;
}

int factorial_loop(int n)
{
	int n_fac = 1;
	for (int i = 1; i <= n; i++) {
		n_fac *= i;
		counts++;
	}
	return n_fac;
}


// recursion
int factorial(int n)
{
	if (n == 0) return 1; // 0! = 1 // 이 부분에 대한 예외처리
	if (n == 1)
		return n;
	else
		return n * factorial(n - 1);
}
