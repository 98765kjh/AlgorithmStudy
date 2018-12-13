#include <iostream>
#include <string>
using namespace std;

int map[26] = { 3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,7,7, 8,8,8,8, 9,9,9, 10,10,10,10 };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int sum = 0;
	string S;

	cin >> S;

	for (int i = 0; i < S.length(); ++i) {
		if (S.at(i) == ' ') {
			sum += 2;
		}
		else if (S.at(i) - 'A' >= 0 && S.at(i) - 'A' < 26) {
			sum += map[S.at(i) - 'A'];
		}
	}
	cout << sum;

	return 0;
}