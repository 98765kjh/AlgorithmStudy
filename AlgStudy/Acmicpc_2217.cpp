#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> rope;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int weight;
	for (int i = 0; i < N; i++)
	{
		cin >> weight;
		rope.push_back(weight);
	}
	
	sort(rope.begin(), rope.end());

	int max = 0;
	int size = N;
	for (auto k : rope)
	{
		if (max < k * size) {
			max = k * size;
		}
		size = size - 1;
	}

	cout << max;

	return 0;
}