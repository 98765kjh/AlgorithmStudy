#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int sum = 0, N;
	int T = 5;

	while (T--) {
		cin >> N;
		if (N < 40) N = 40;
		sum += N;
	}

	cout << sum/5;
	
	return 0;
}