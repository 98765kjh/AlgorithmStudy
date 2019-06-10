#include <iostream>

using namespace std;

#define MAX 6

int main()
{
	int money[MAX] = {500, 100, 50, 10, 5, 1};
	int price;

	cin >> price;

	int balance = 1000 - price;
	int coin_sum = 0;

	for (int i = 0; i < MAX; i++)
	{
		int coin = 0;
		if (balance >= money[i]) {
			coin = balance / money[i];
			balance = balance % money[i];

			coin_sum = coin_sum + coin;
		}
	}

	cout << coin_sum;

	return 0;
}