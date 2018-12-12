#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct bus
{
	int a, b;
	int num;
};

bool comp(const bus &a, const bus &b)
{
	return (a.a != b.a) ? a.a < b.a : a.b > b.b;
}

bool check[500001];

int main()
{
	int N, M;
	unsigned int i;
	vector<bus> V;
	bus bus_tmp;
	scanf("%d%d", &N, &M);

	int b_max = 0;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &bus_tmp.a, &bus_tmp.b);
		bus_tmp.num = i + 1;
		V.push_back(bus_tmp);
		if (bus_tmp.a > bus_tmp.b) {
			b_max = max(b_max, V[i].b);
			V[i].b += N;
		}
	}
	sort(V.begin(), V.end(), comp);

	for (i = 0; i < V.size(); i++) {
		if (b_max >= V[i].b) {
			check[V[i].num] = true;
		}
		else {
			b_max = V[i].b;
		}
	}

	for (int i = 1; i <= M; i++) {
		if (!check[i])
			printf("%d ", i);
	}
	printf("\n");
	

	return 0;
}