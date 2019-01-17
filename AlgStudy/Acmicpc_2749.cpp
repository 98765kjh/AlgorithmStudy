#include <iostream>
using namespace std;

long long int num;
int mod = 1000000;
const int p = 100000 * 15;	// period
int fib[p] = { 0,1 };

int main()
{
	cin >> num;
	
	for (int i = 2; i < p; i++)
	{
		fib[i] = fib[i - 2] + fib[i - 1];
		fib[i] = fib[i] % mod;
	}
	cout << fib[num%p] << '\n';

	return 0;
}