#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int check[8001];

int main()
{
	int T, tmp;
	vector<int> arr;
	int sum = 0;

	cin >> T;
	while (T--)
	{
		cin >> tmp;
		sum += tmp;
		arr.push_back(tmp);
		check[tmp + 4000]++;
	}
	sort(arr.begin(), arr.end());
	
	// »ê¼úÆò±Õ
	//if (sum < 0) cout << (sum - 1) / (int)arr.size() << '\n';
	//else cout << sum / (int)arr.size() << '\n';
	cout << floor((double)sum / (double)arr.size() + 0.5) << '\n';

	// Áß¾Ó°ª
	cout << arr[arr.size() / 2] << '\n';

	// ÃÖºó°ª
	int preq_max = -1;
	for (int i = 1; i < 8001; i++)
	{
		if (preq_max < check[i])
			preq_max = check[i];
	}

	tmp = 0;
	int second = -5555;
	for (int i = 1; i < 8001; i++)
	{
		if (check[i] == preq_max)
		{
			tmp++;
			second = i - 4000;
		}
		if (tmp == 2)
		{
			second = i - 4000;
			break;
		}
	}
	cout << second << '\n';


	// ¹üÀ§
	cout << arr[arr.size() - 1] - arr[0] << '\n';

	return 0;
}
