#include <iostream>
using namespace std;

int main()
{
	int num;
	int cnt;
	int arr[7];

	cin >> num;

	cnt = 0;
	arr[0] = 1;
	for (int i = 1; i < 7; i++)
		arr[i] = arr[i - 1] * 2;

	for (int i = 6; i >= 0; i--) {
		if (num >= arr[i]) {
			cnt++;
			num -= arr[i];
		}
	}
	cout << cnt << endl;

	return 0;
}