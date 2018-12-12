#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int fruit[10001];
vector<int> edge[10001];
bool checked[10001];
int N;
int sum;

typedef struct _
{
	int index;
	int fruit;
	int start;
}st;

void bfs()
{
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	int num, a, b;
	int max = 0, max_pos = 0, pos = 1;
	sum = 0;

	cin >> N;
	for (int i = 0; i <= N; i++)
		fruit[i] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		fruit[i] = num;
		checked[i] = false;
		sum += num;
	}
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	queue<st> q;
	bool check[10001];
	st now, tmp;

	max = 0;

	for (int k = 1; k <= N; k++)
	{
		if (edge[k].size() > 2)
			continue;

		for (int i = 0; i <= N; i++)
			check[i] = false;

		tmp.index = k;
		tmp.fruit = fruit[k];
		tmp.start = k;
		q.push(tmp);

		check[k] = true;
		//cout << src << " ";
		bool flag;

		while (!q.empty()) {
			now = q.front();
			flag = true;
			for (int i = 0; i < edge[now.index].size(); i++) {
				int pos = edge[now.index][i];
				if (!check[pos]) {
					check[pos] = true;
					//cout << edge[top][i] << " ";
					tmp.index = pos;
					tmp.fruit = now.fruit + fruit[pos];
					tmp.start = now.start;
					if (now.fruit == 0 && now.start > pos)
						tmp.start = pos;
					q.push(tmp);
					flag = false;
				}
			}
			if (flag) {
				if (sum == now.fruit) {
					cout << now.fruit << " " << now.start << endl;
					return 0;
				}
				if (max < now.fruit) {
					max = now.fruit;
					max_pos = now.start;
				}
			}
			q.pop();
		}
		//cout << endl;

	}
	cout << max << " " << max_pos << endl;

	return 0;
}