#include <iostream>
using namespace std;

bool isPrime[1000001];	// false = prime

void checkPrime(int max)
{
	isPrime[0] = isPrime[1] = true;
	isPrime[2] = false;
	for (int num = 2; num <= max; num++)
	{
		if (isPrime[num])	continue;
		for (int i = num * 2; i <= max; i = i + num)
		{
			isPrime[i] = true;
		}
	}
}

int cntPrime(int n)
{
	int cnt = 0;
	for (int i = n+1; i <= 2 * n; i++)
	{
		if (!isPrime[i])	cnt++;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M;

	checkPrime(123456*2);
	while (1)
	{
		cin >> M;
		if (M == 0)
			break;

		cout << cntPrime(M) << '\n';
	}

	return 0;
}