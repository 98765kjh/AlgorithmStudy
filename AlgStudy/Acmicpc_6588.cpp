#include <iostream>
#include <cstdio>
using namespace std;

bool isPrime[1000001];	// false = prime

void checkPrime(int max)
{
	isPrime[0] = isPrime[1] = true;
	isPrime[2] = false;
	for (int num = 2; num <= max; num++)
	{
		if (isPrime[num])	continue;
		for (int i = num * 2; i <= max; i += num)
		{
			isPrime[i] = true;
		}
	}
}

void getGB(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (!isPrime[i] && !isPrime[num - i])
		{
			printf("%d = %d + %d\n", num, i, num - i);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.");
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, num;

	checkPrime(1000000);

	while(1)
	{
		cin >> num;
		if (num == 0)	break;

		getGB(num);
	}

	return 0;
}