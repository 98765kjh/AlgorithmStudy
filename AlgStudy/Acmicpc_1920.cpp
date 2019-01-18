#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> arr;
	int N, M, num;

	cin >> N;
	while (N--)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	cin >> M;
	while (M--)
	{
		cin >> num;
		cout << binary_search(arr.begin(), arr.end(), num) << '\n';
	}

	return 0;
}