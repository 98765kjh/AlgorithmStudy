#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > arr;
vector<int> lis;
int N;

int main()
{
	int b;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> b;
		arr.push_back(make_pair(i, b));
	}
	sort(arr.begin(), arr.end());

	vector<int>::iterator it;
	lis.push_back(0);
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if (lis[lis.size() - 1] < arr[i].second) {
			lis.push_back(arr[i].second);
		}
		else {
			it = lower_bound(lis.begin(), lis.end(), arr[i].second);
			(*it) = arr[i].second;
		}
	}

	cout << (lis.size() - 1);

	return 0;
}