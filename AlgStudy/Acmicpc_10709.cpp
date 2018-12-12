#include <iostream>
using namespace std;

int main()
{
	int H, W;
	int cloud[100][100];
	char c;
	int pos;

	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> c;
			if (c == 'c')
				cloud[i][j] = 0;
			else
				cloud[i][j] = -1;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W - 1; j++)
		{
			if (cloud[i][j] != -1 && cloud[i][j + 1] != 0)
				cloud[i][j + 1] = cloud[i][j] + 1;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << cloud[i][j]<<" ";
		cout << endl;
	}
	return 0;
}