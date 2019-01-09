#include <iostream>
using namespace std;

bool isPrime(int num)
{
	if (num < 2)	return false;
	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0) return false;
	}
	return true;
}

int main()
{
	int M, N;
	int sum = 0;
	int min = 99999;

	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (i % 2 == 0 && i!=2) continue;
		if (isPrime(i))
		{
			sum += i;
			if (min > i) min = i;
		}
	}
	if (sum == 0)
		cout << "-1\n";
	else 
		cout << sum << '\n' << min << '\n';

	return 0;
}