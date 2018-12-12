#include <iostream>
using namespace std;

short up[100000];
short down[100000];
int DP[3][100000];

int main()
{
	ios::sync_with_stdio(false);

	int T;
	int N;

	int tmp1, tmp2;

	cin >> T;
	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> up[i];
		for (int i = 0; i < N; i++)
			cin >> down[i];

		DP[0][0] = 0;
		DP[1][0] = up[0];
		DP[2][0] = down[0];

		for (int i = 1; i < N; i++) {
			DP[0][i] = DP[1][i - 1]>DP[2][i - 1] ? DP[1][i - 1] : DP[2][i - 1];
			DP[1][i] = (DP[0][i - 1] + up[i])>(DP[2][i - 1] + up[i]) ? DP[0][i - 1] + up[i] : DP[2][i - 1] + up[i];
			DP[2][i] = (DP[0][i - 1] + down[i])>(DP[1][i - 1] + down[i]) ? DP[0][i - 1] + down[i] : DP[1][i - 1] + down[i];
		}

		int max = DP[0][N - 1] > DP[1][N - 1] ? DP[0][N - 1] : DP[1][N - 1];
		max = max > DP[2][N - 1] ? max : DP[2][N - 1];

		cout << max << endl;


	}

	return 0;
}