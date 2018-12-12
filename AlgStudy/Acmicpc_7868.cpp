#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long int fow(long long int p, int k)
{
	long long int ret = 1;
	for (int i = 0; i < k; i++)
	{
		ret *= p;
		if (ret < 0)
			return 0;
	}
	return ret;
}

int main()
{
	long long int p1, p2, p3;
	int i;
	int cnt = 0;
	vector<long long int> arr;
	long long int tmp;

	cin >> p1 >> p2 >> p3 >> i;

	for (int a = 0; a < 57; a++)
	{
		for (int b = 0; b < 46; b++)
		{
			for (int c = 0; c < 24; c++)
			{
				tmp = fow(p1, a) * fow(p2, b) * fow(p3, c);
				if (tmp > 0)
					arr.push_back(tmp);
			}
		}
	}

	sort(arr.begin(), arr.end());

	cout << arr.at(i) << endl;
}