#include <stdio.h>
#include <queue>
using namespace std;

int to[100][100][100];
struct str
{
	int i, j, k;
};
int main()
{
	int M, N, H;
	int cnt = 0;

	scanf("%d%d%d", &M, &N, &H);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				scanf("%d", &to[H][N][M]);
				if (to[H][N][M] == 0) {
					cnt++;
				}
			}

	int i, j, k;
	str tmp;
	for (i = 0; i < H; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++)
				if (to[H][N][M] == 1) {
					tmp.i = N;
					tmp.j = M;
					tmp.k = H;
					goto out;
				}
out:

	queue<str> que;

	que.push(tmp);

	while (!que.empty()) {
		tmp = que.front();

		if (tmp.i - 1 >= 0) {
			if (to[tmp.i - 1][tmp.j][tmp.k] == 0) {
				to[tmp.i - 1][tmp.j][tmp.k] = 1;
				cnt--;
				que.push({ tmp.i - 1,tmp.j,tmp.k });
			}
			else if (to[tmp.i - 1][tmp.j][tmp.k] == 1)
				que.push({ tmp.i - 1,tmp.j,tmp.k });
		}
		if (tmp.i + 1 <= H) {
			if (to[tmp.i + 1][tmp.j][tmp.k] == 0) {
				to[tmp.i + 1][tmp.j][tmp.k] = 1;
				cnt--;
				que.push({ tmp.i + 1,tmp.j,tmp.k });
			}
			else if (to[tmp.i + 1][tmp.j][tmp.k] == 1)
				que.push({ tmp.i + 1,tmp.j,tmp.k });
		}
		if (tmp.j - 1 >= 0) {
			if (to[tmp.i][tmp.j - 1][tmp.k] == 0) {
				to[tmp.i][tmp.j - 1][tmp.k] = 1;
				cnt--;
				que.push({ tmp.i, tmp.j - 1, tmp.k });
			}
			else if (to[tmp.i][tmp.j - 1][tmp.k] == 1)
				que.push({ tmp.i,tmp.j - 1,tmp.k });
		}
		if (tmp.j + 1 <= M) {
			if (to[tmp.i][tmp.j + 1][tmp.k] == 0) {
				to[tmp.i][tmp.j + 1][tmp.k] = 1;
				cnt--;
				que.push({ tmp.i,tmp.j + 1,tmp.k });
			}
			else if (to[tmp.i][tmp.j + 1][tmp.k] == 1)
				que.push({ tmp.i,tmp.j + 1,tmp.k });
		}
		if (tmp.k - 1 >= 0) {
			if (to[tmp.i][tmp.j][tmp.k - 1] == 0) {
				to[tmp.i][tmp.j][tmp.k - 1] = 1;
				cnt--;
				que.push({ tmp.i,tmp.j,tmp.k - 1 });
			}
			else if (to[tmp.i][tmp.j][tmp.k - 1] == 1)
				que.push({ tmp.i,tmp.j,tmp.k - 1 });
		}
		if (tmp.k + 1 <= N) {
			if (to[tmp.i][tmp.j][tmp.k + 1] == 0) {
				to[tmp.i][tmp.j][tmp.k + 1] = 1;
				cnt--;
				que.push({ tmp.i,tmp.j,tmp.k + 1 });
			}
			else if (to[tmp.i][tmp.j][tmp.k + 1] == 1)
				que.push({ tmp.i,tmp.j,tmp.k + 1 });
		}

		que.pop();
	}

	return 0;
}