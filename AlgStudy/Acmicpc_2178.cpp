#include <cstdio>
#include <queue>
using namespace std;

/*
	BFS 최단경로 기본 문제
*/

bool map[100][100];
bool ischeck[100][100];

struct pos {
	int y;
	int x;
	int cnt;
};

int len;
int n, m;

int bfs(pos p);

int main()
{
	int i, j;
	char str[100];

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		for (j = 0; j < m; j++) {
			if (str[j] == '0')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		
		}
	}

	len = 0;
	pos p = { 0,0,1 };
	bfs(p);

	printf("%d", len);

	return 0;
}

int bfs(pos p)
{
	queue<pos> que;

	que.push(p);
	ischeck[p.y][p.x] = true;
	pos tmp;

	while (!que.empty()) {
		tmp = que.front();
		que.pop();
		if (tmp.x == m - 1 && tmp.y == n - 1) {

			break;
		}

		if (tmp.x + 1 < m && map[tmp.y][tmp.x + 1] && !ischeck[tmp.y][tmp.x + 1]) {
			que.push({ tmp.y,tmp.x + 1, tmp.cnt + 1});
			ischeck[tmp.y][tmp.x + 1] = true;
		}
		if (tmp.y + 1 < n && map[tmp.y + 1][tmp.x] && !ischeck[tmp.y + 1][tmp.x]) {
			que.push({ tmp.y + 1,tmp.x, tmp.cnt + 1});
			ischeck[tmp.y + 1][tmp.x] = true;
		}
		if (tmp.x - 1 >= 0 && map[tmp.y][tmp.x - 1] && !ischeck[tmp.y][tmp.x - 1]) {
			que.push({ tmp.y,tmp.x - 1, tmp.cnt + 1 });
			ischeck[tmp.y][tmp.x - 1] = true;
		}
		if (tmp.y - 1 >= 0 && map[tmp.y - 1][tmp.x] && !ischeck[tmp.y - 1][tmp.x]) {
			que.push({ tmp.y - 1,tmp.x, tmp.cnt + 1 });
			ischeck[tmp.y - 1][tmp.x] = true;
		}
	}
	len = tmp.cnt;
	return 0;
}