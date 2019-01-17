#include <iostream>
using namespace std;

unsigned long long int Comb[30][30];

int main()
{
	int T;
	int N, M;

	// Initialize
	for (int j = 1; j < 30; j++) {
		Comb[j][0] = 1;
		Comb[j][1] = j;
	}

	// Set Combination value (under 30)
	for (int i = 2; i < 30; i++)
		for (int j = 1; j < 30; j++)
			Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];

	// Test input / output
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		cout << Comb[M][N] << '\n';
	}

	return 0;
}