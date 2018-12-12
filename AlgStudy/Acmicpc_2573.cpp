#include <iostream>
using namespace std;

int N, M;
short ice[300][300];
short mem[300][300];
bool ischecked[300][300];
int num;

void calc()
{
	int i, j;
	int tmp;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			tmp = 0;

			if (ice[i][j] == 0)
				continue;

			if (i - 1 >= 0 && mem[i - 1][j] == 0)
				tmp++;
			if (i + 1 < N && mem[i + 1][j] == 0)
				tmp++;
			if (j - 1 >= 0 && mem[i][j - 1] == 0)
				tmp++;
			if (j + 1 < M && mem[i][j + 1] == 0)
				tmp++;

			ice[i][j] = (ice[i][j] - tmp) < 0 ? 0 : ice[i][j] - tmp;
			if (ice[i][j] == 0)
				num--;
		}
	}
}

int check(int i, int j)
{
	int ret = 1;

	ischecked[i][j] = true;
	
	if (i - 1 >= 0 && ice[i - 1][j] != 0 && ischecked[i - 1][j] == false)
		ret += check(i - 1, j);
	if (i + 1 <= N && ice[i + 1][j] != 0 && ischecked[i + 1][j] == false)
		ret += check(i + 1, j);
	if (j - 1 >= 0 && ice[i][j - 1] != 0 && ischecked[i][j - 1] == false)
		ret += check(i, j - 1);
	if (j + 1 <= M && ice[i][j + 1] != 0 && ischecked[i][j + 1] == false)
		ret += check(i, j + 1);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int i, j, t;
	int x, y;

	//scanf("%d%d", &N, &M);
	cin >> N >> M;

	num = 0;
	t = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			//scanf("%d", &ice[i][j]);
			cin >> ice[i][j];
			if (ice[i][j] != 0)
				num++;
		}

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			mem[i][j] = ice[i][j];

	while(1)
	{
		// 덩어리 검사
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				ischecked[i][j] = false;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
				if (ice[i][j] != 0)
				{
					x = i;
					y = j;
					break;
				}
			if (ice[i][j] != 0)
				break;
		}

		if (i == N&&j == M&&ice[i][j] == 0)
		{
			t = 0;
			break;
		}
		//cout << num << endl;
		if (check(x, y) < num)
		{
			break;
		}
		t++;
		// 빙산이 녹음
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				mem[i][j] = ice[i][j];

		calc();

	}

	//printf("%d\n", t);
	cout << t << endl;
	
	return 0;
}