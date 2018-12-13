#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	int R;
	string S;

	cin >> T;

	while (T--)
	{
		cin >> R >> S;
		for (int i = 0; i < S.length(); ++i) {
			for (int k = 0; k < R; ++k) {
				cout << S.at(i);
			}
		}
		cout << '\n';
	}

	return 0;
}