#include <iostream>
#include <string>
using namespace std;
long long dp[100][2][20];

int main()
{
	string dev, ang;
	string str;

	cin >> str >> dev >> ang;

	for (int i = 0; i < dev.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			if (dev[i] == str[j]) {
				if (j == 0) {
					dp[i][0][j] = 1;
				}
				else {
					for (int k = 0; k < i; k++) {
						dp[i][0][j] += dp[k][1][j - 1];
					}
				}
			}
			if (ang[i] == str[j]) {
				if (j == 0) {
					dp[i][1][j] = 1;
				}
				else {
					for (int k = 0; k < i; k++) {
						dp[i][1][j] += dp[k][0][j - 1];
					}
				}
			}
		}
	}

	long long result = 0;
	for (int i = 0; i < dev.length(); i++) {
		result += dp[i][0][str.length() - 1];
		result += dp[i][1][str.length() - 1];
	}

	cout << result << endl;
	return 0;
}