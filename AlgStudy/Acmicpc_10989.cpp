#include <iostream>
using namespace std;

int arr[10001];

int main()
{
	ios::sync_with_stdio(false);

	int T, tmp;

	cin >> T;
	while (T--)
	{
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int k = 0; k < arr[i]; k++)
			cout << i << '\n';

	return 0;
}