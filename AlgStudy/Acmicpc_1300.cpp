#include <iostream>
using namespace std;

/*
	�̺�Ž���ε� ���Ƴ��Ƽ� ���� �� �ȵ���

*/

int arr_size, index;

int b_search(int start, int end)
{
	int mid, count;
	int ans;
	while (start <= end)
	{
		mid = (start + end) / 2;

		count = 0;
		for (int i = 1; i <= arr_size; i++)
		{
			int div = mid / i;
			count += div < arr_size ? div : arr_size;
		}
		if (count >= index) {
			ans = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr_size >> index;

	cout << b_search(1, index) << '\n';

	return 0;
}