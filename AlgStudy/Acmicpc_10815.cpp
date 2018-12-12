#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num;
int arr[500000];
int result[500000];

int binarySearch(int bottom, int top, int num)
{
	int low = 0, high = top - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] < num)
			low = mid + 1;
		else if (arr[mid]>num)
			high = mid - 1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr+N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		result[i] = binarySearch(0, N, num);
	}

	for (int i = 0; i < M; i++)
		cout << result[i] << " ";
	cout << endl;
}