#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int money[10];

	cin >> N >> K;

	for(int i = N-1; i>=0; i--)
	{
		cin >> money[i];
	}

	int coin_sum = 0;
	for (int i = 0; i < N; i++)
	{
		int coin = 0;
		if (K >= money[i]) {
			coin = K / money[i];
			K = K % money[i];

			coin_sum = coin_sum + coin;
		}
	}

	cout << coin_sum;
}