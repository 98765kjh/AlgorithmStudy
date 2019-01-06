#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int x;
	int arr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		x = pow(10, 9 - i);
		arr[9 - i] = num / x;
		num = num % x;
	}

	int zero_pos = 0;
	for (int i = 9; i >= 0; i--) {
		if (arr[i] != 0) {
			zero_pos = i;
			break;
		}
	}
	zero_pos += 1;

	sort(arr, arr + zero_pos, greater<int>());

	for (int i = 0; i < zero_pos; i++)
	{
		cout << arr[i];
	}

}