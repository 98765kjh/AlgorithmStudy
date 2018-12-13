#include <iostream>
using namespace std;

int reverse(int N)
{
	int _100 = N / 100;
	int _10 = (N % 100) / 10;
	int _1 = (N % 10);

	return _1 * 100 + _10*10 + _100;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	A = reverse(A);
	B = reverse(B);

	if (A > B)	cout << A;
	else		cout << B;
}