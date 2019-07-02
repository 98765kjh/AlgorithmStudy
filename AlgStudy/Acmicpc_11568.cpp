#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> lis;
vector<int>::iterator it;

int main()
{
	int N, num;
	
	cin >> N;
	while (N--) {
		cin >> num;
		arr.push_back(num);
	}
	
	lis.push_back(0);
	int pLis = 0;
	for (int pArr = 0; pArr < arr.size(); pArr++)
	{
		if (lis[pLis] < arr[pArr]) {
			lis.push_back(arr[pArr]);
			pLis++;
		}
		else {
			it = lower_bound(lis.begin(), lis.end(), arr[pArr]);
			*it = arr[pArr];
		}
	}

	cout << lis.size() - 1;

	return 0;
}