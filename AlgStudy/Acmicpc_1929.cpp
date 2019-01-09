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

int main()
{
	int M, N;
	int sum = 0;
	int min = 99999;

	cin >> M >> N;

	checkPrime(N);
	for (int i = M; i <= N; i++)
	{
		if (!isPrime[i])	cout << i << '\n';
	}

	return 0;
}