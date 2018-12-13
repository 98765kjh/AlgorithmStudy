#include <iostream>
#include <string>
using namespace std;

int checkGroupWord(string S)
{
	bool check[26];
	char ch = '*';
	for (int i = 0; i < 26; ++i)	check[i] = false;

	for (int i = 0; i < S.length(); ++i) {
		if (ch != S.at(i)) {
			ch = S.at(i);
			if (check[ch - 'a']) {
				return 0;
			}
			else {
				check[ch - 'a'] = true;
			}
		}
	}
	return 1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	string S;
	int n = 0;

	cin >> T;
	while (T--)
	{
		cin >> S;
		n += checkGroupWord(S);
	}

	cout << n;

	return 0;
}