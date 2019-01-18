#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long int ULLI;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ULLI K, N, num;
	vector<ULLI> arr;
	ULLI sum = 0;

	cin >> K >> N;
	while (K--)
	{
		cin >> num;
		sum = sum + num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	ULLI upper_bound = arr[arr.size() - 1] + 1;
	ULLI lower_bound = 1;
	ULLI bound = 1;
	
	ULLI count;
	while (1)
	{

		bound = (upper_bound + lower_bound) / 2;
		count = 0;

		if (lower_bound == upper_bound)	break;
		else if (lower_bound == (upper_bound - 1)) break;

		for (auto a : arr)
		{
			count = count + a / bound;
		}


		if (count < N)
		{
			upper_bound = bound;
		}
		else
		{
			lower_bound = bound;
		}


	}
	cout << bound << '\n';

	return 0;
}