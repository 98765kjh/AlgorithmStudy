#include <iostream>
using namespace std;

#define MAX 3072

char mat[MAX][2 * MAX];

void star(int k, int x, int y)
{
	if (k == 3) {
		mat[y][x + 2] = '*';
		mat[y + 1][x + 1] = '*';
		mat[y + 1][x + 3] = '*';
		mat[y + 2][x] = '*';
		mat[y + 2][x + 1] = '*';
		mat[y + 2][x + 2] = '*';
		mat[y + 2][x + 3] = '*';
		mat[y + 2][x + 4] = '*';
	}
	else {
		star(k / 2, x + (k / 2)	, y);
		star(k / 2, x			, y + k / 2);
		star(k / 2, x + k		, y + k / 2);
	}
}

int main()
{
	int N;

	cin >> N;

	star(N, 0, 0);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < 2 * N; ++x) {
			if (mat[y][x] != '*') {
				cout << " ";
			}
			else {
				cout << mat[y][x];
			}
		}
		cout << '\n';
	}

	return 0;
}