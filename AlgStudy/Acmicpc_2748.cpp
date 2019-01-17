#include <iostream>

using namespace std;

long long int fib[91];

void fibonacci(int n)
{
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 2] + fib[i - 1];
	}
}

int main()
{
	int n;

	fibonacci(90);

	cin >> n;

	cout << fib[n] << '\n';

	return 0;
}