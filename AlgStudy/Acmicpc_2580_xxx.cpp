#include <stdio.h>
#pragma warning (disable:4996)

int sd[9][9];
int chk[9][9][10];

void check(int, int);
void check_rev(int, int);
bool solve(int, int);

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			scanf("%d", &sd[i][j]);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sd[i][j] != 0)
				check(i, j);
		}
	}

	solve(0, -1);

	printf("\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", sd[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void check(int i, int j)
{
	for (int k = 0; k < 9; k++)
	{
		chk[i][k][sd[i][j]]++;
		chk[k][j][sd[i][j]]++;
	}
	for (int k = 3 * (i / 3); k < 3 * ((i / 3) + 1); k++)
	{
		for (int f = 3 * (j / 3); f < 3 * ((j / 3) + 1); f++)
		{
			chk[k][f][sd[i][j]]++;
		}
	}
}

bool solve(int x, int y)
{
	int tmp;
	for (int i = x; i < 9; i++)
	{
		if (i == x) tmp = y + 1; else tmp = 0;
		for (int j = tmp; j < 9; j++)
		{
			if (sd[i][j] == 0)
			{
				for (int k = 1; k < 10; k++)
				{
					if (!chk[i][j][k])
					{
						sd[i][j] = k;
						check(i, j);
						if (solve(i, j))
							return true;
						check_rev(i, j);
						sd[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}

void check_rev(int i, int j)
{
	for (int k = 0; k < 9; k++)
	{
		chk[i][k][sd[i][j]]--;
		chk[k][j][sd[i][j]]--;
	}
	for (int k = 3 * (i / 3); k < 3 * ((i / 3) + 1); k++)
	{
		for (int f = 3 * (j / 3); f < 3 * ((j / 3) + 1); f++)
		{
			chk[k][f][sd[i][j]]--;
		}
	}
}