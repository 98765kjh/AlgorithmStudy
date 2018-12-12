/* 런타임 에러 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct land
{
	int area;
	int label;
	int x, y;
};
land area[100][100];
bool check[100][100];
vector<pair<int, int> > vec[100];
int num = 1;
queue<land> que;
land tmp;

int getlen(int a, int b)
{
	if (a > b) {
		return a - b;
	}
	else
		return b - a;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> area[i][j].area;
			check[i][j] = false;
			area[i][j].x = j;
			area[i][j].y = i;
			if (area[i][j].area == 0)
				area[i][j].label = -1;
			else
				area[i][j].label = 0;
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] || area[i][j].label == -1)
				continue;
			que.push(area[i][j]);
			check[i][j] = true;
			while (!que.empty()) {
				tmp = que.front();
				if (tmp.label != 0) {
					que.pop();
				}
				else {
					area[tmp.y][tmp.x].label = num;
					vec[num].push_back({ tmp.x,tmp.y });
					if (tmp.y - 1 >= 0 && area[tmp.y - 1][tmp.x].label == 0 && !check[tmp.y - 1][tmp.x]) {
						que.push(area[tmp.y - 1][tmp.x]);
						check[tmp.y - 1][tmp.x] = true;
					}
					if (tmp.y + 1 < N && area[tmp.y + 1][tmp.x].label == 0 && !check[tmp.y + 1][tmp.x]) {
						que.push(area[tmp.y + 1][tmp.x]);
						check[tmp.y + 1][tmp.x] = true;
					}
					if (tmp.x - 1 >= 0 && area[tmp.y][tmp.x - 1].label == 0 && !check[tmp.y][tmp.x - 1]) {
						que.push(area[tmp.y][tmp.x - 1]);
						check[tmp.y][tmp.x - 1] = true;
					}
					if (tmp.x + 1 < N && area[tmp.y][tmp.x + 1].label == 0 && !check[tmp.y][tmp.x + 1]) {
						que.push(area[tmp.y][tmp.x + 1]);
						check[tmp.y][tmp.x + 1] = true;
					}
					que.pop();
				}
			}
			num++;
		}
	}

	int len = 999999999;

	if (num == 1 || num == 2) {
		cout << "0" << endl;
		return 0;
	}
	int tmp_len;
	for (int i = 1; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			for (int a = 0; a < vec[i].size(); a++) {
				for (int b = 0; b < vec[j].size(); b++) {
					tmp_len = getlen(vec[i][a].first, vec[j][b].first) + getlen(vec[i][a].second, vec[j][b].second) - 1;
					if (tmp_len < len)
						len = tmp_len;
				}
			}
		}
	}

	cout << len << endl;

	return 0;
}