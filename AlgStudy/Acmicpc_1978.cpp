#include <iostream>

using namespace std;

bool isPrime(int num)
{
	if (num < 2)	return false;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num%i == 0) return false;
	}
	return true;
}

int main()
{
	int N, num, cnt = 0;

	cin >> N;
	while (N--)
	{
		cin >> num;
		if (isPrime(num))	cnt++;
	}
	cout << cnt << '\n';
}