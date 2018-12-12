#include <iostream>
#include <vector>
using namespace std;

/* 펜윅 트리 문제 */

int sum(vector<int> &tree, int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(vector<int> &tree, int pos, int diff)
{
	while (pos < tree.size()) {
		tree[pos] += diff;
		pos += (pos&-pos);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> a(N + 1);
	vector<int> tree(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		update(tree, i, a[i]);
	}


	return 0;
}