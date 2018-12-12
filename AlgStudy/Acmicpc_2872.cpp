#include <iostream>
using namespace std;

int arr[300000];

int main()
{
	ios::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)	cin >> arr[i];

	int l = N;
	for (int i = N - 1; i >= 0; i--)
		if (arr[i] == l)
			l--;

	cout << l << endl;

	return 0;
}