#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<vector<int> > vec;
int bMatch[5000];
int edge[5000][5000];
bool check[5000];
int cnt;
int n, m;

int dfs(int now)
{
	if (check[now])
		return 0;
	check[now] = true;
	int ret = 0;
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (bMatch[next]==-1 || dfs(bMatch[next]) ) {
			bMatch[next] = now;
			return 1;
		}
	}
	return 0;
}

int BipMatch()
{
	memset(bMatch, -1, sizeof(bMatch));
	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		memset(check, false, sizeof(check));
		ans += dfs(i);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	int src, des;

	cin >> T;
	while (T--)
	{
		cin >> n >> m;

		vec.clear();

		vec.resize(n);

		for (int i = 0; i < m; i++) {
			cin >> src >> des;
			vec[src].push_back(des);
		}

		cout << BipMatch() << endl;
	}

	return 0;
}