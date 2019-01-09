#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	vector<int> arr;
	int T, tmp;

	cin >> T;

	while (T--)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (auto k : arr)
		cout << k << '\n';

	return 0;
}