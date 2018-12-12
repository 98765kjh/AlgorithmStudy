#include <iostream>
using namespace std;

long long a, b, c;
long long result;

long long f(int x, int n) { // x^n을 반환

	if (n == 0) return 1;

	if (n % 2 == 1) return (x*f(x, n - 1))%c; // n이 홀수일 때
	else { // n이 짝수일 때
		long long half = f(x, n / 2)%c;
		return (half*half)%c; // x^(n/2)의 제곱을 반환
	}
}

int main()
{
	result = 0;

	cin >> a >> b >> c;

	result = f(a, b);

	cout << result << endl;

	return 0;
}