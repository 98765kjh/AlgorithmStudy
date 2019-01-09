#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByLength(const string &a, const string &b)
{
	return a.length() < b.length();
}
bool sortByDictionary(const string &a, const string &b)
{
	if (a.length()==b.length())	return a < b;
	else return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);

	vector<string> arr;
	int T;
	string str_tmp;

	cin >> T;
	while (T--)
	{
		cin >> str_tmp;
		arr.push_back(str_tmp);
	}

	sort(arr.begin(), arr.end(), sortByDictionary);
	//sort(arr.begin(), arr.end(), sortByLength);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (auto str : arr) {
		cout << str << '\n';
	}

	return 0;
}