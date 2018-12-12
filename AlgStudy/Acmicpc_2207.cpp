#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> edge[10001];

int main()
{
	ios::sync_with_stdio(false);

	int a, b;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	return 0;
}