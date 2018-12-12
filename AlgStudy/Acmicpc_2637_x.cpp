#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> part[101];
bool isBC[101];
int N, M;

bool ischeck[101];
int mem[101][101];

int result[101];

void make(int pos)
{
	ischeck[pos] = true;
	for (int i = 0; i < part[pos].size(); i++) {
		int now = part[pos][i].first;

		if (isBC[now] ) {
			result[now] += part[pos][i].second;
		}
		else if (ischeck[now]) {
			for (int i = 1; i < N; i++) {
				if (mem[now][i] != 0) {
					result[i] += mem[now][i];
				}
			}
		}
		else {
			make(part[pos][i].first);
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		isBC[i] = true;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		part[a].push_back({ b,c });
		isBC[a] = false;
	}

	make(N);

	return 0;
}