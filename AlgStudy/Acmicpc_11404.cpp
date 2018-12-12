#include <iostream>
using namespace std;

/* 플로이드 와셜 알고리즘 


	모든 경로를 찾을 수 있음. */

int d[100][100];
int p[100][100];

int main()
{
	int N, M;
	int a, b, c;

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			d[i][j] = 999999999;
			p[i][j] = -1;
			if (i == j)
				d[i][j] = 0;
		}

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if(d[a][b]>c)
			d[a][b] = c;
		p[a][b] = a;
	}
	/*
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			d[i][j] = p[i][j];
			*/
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[j][i]>d[j][k] + d[k][i]) {
					d[j][i] = d[j][k] + d[k][i];
					p[j][i] = p[k][i];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}