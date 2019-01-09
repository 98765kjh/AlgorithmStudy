#include <iostream>
using namespace std;

bool isPrime[10001];	// false = prime

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
	for (int i = num/2; i >= 2; i--)
	{
		if (!isPrime[i] && !isPrime[num - i])
		{
			cout << i << " " << num - i << '\n';
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, num;

	checkPrime(10000);
	
	cin >> T;
	while (T--)
	{
		cin >> num;
		getGB(num);
	}

	return 0;
}