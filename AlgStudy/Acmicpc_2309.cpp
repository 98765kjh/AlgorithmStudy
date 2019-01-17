#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height[9];
bool check[9];
int sum;

int getSum()
{
	int num = sum;
	for (int i = 0; i < 9; i++)
		if (!check[i])
			num = num - height[i];

	return num;
}
void getResult()
{
	vector<int> vec;
	for (int i = 0; i < 9; i++)
		if (check[i])
			vec.push_back(height[i]);
	sort(vec.begin(), vec.end());

	for (auto k : vec)
		cout << k << '\n';
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i];
		check[i] = true;
	}

	for (int i = 0; i < 9; i++)
	{
		check[i] = false;
		for (int j = 8; j > i; j--)
		{
			check[j] = false;
			if (getSum() == 100) {
				getResult();
				return 0;
			}
			check[j] = true;
		}
		check[i] = true;
	}
}