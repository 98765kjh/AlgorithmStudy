#include <iostream>
#include <vector>
using namespace std;


int f(int set[], int x)
{
	if (set[x] == x)
		return x;
	return set[x] = f(set, set[x]);
}
void Union(int set[], int a, int b)
{
	a = f(set, a);
	b = f(set, b);
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}
int find(int set[], int a, int b)
{
	a = f(set, a);
	b = f(set, b);
	if (a == b)
		return 1;
	else
		return 0;
}

int main()
{
	int N;
	int a, b;
	vector<int> vt[101];
	vector<int> edge[20000];
	vector<int> result[101];

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (i == j)
				continue;

			if (a == 0) {
				vt[i + 1].push_back(j + 1);
				vt[j + 1].push_back(i + 1);
			}
		}
	}
	int num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < vt[i].size(); j++) {
			edge[num].push_back(i);
			edge[num].push_back(vt[i][j]);
			num++;
		}
	}

	/*for (int i = 0; i < num; i++)
	{
		cout << edge[i][0] << " " << edge[i][1] << endl;
	}*/

	int set[100];
	for (int i = 0; i <= N; i++)
		set[i] = i;

	for (int i = 0; i < num; i++)
	{
		if (!find(set, edge[i][0], edge[i][1])) {
			Union(set, edge[i][0], edge[i][1]);
		}
	}

	bool ischeck[101];
	for (int i = 0; i <= 100; i++)
		ischeck[i] = false;

	bool flag = false;

	int tmp;
	int count = 0;
	num = 0;
	for (int i = 1; i <= N; i++) {
		if (!ischeck[i]) {
			tmp = set[i];
			//result[count].push_back(i);
			
			for (int k = i; k <= N; k++) {
				if (tmp == set[k]) {
					result[count].push_back(k);
					ischeck[k] = true;
				}
			}

			if (result[count].size() == 1)
				flag = true;
			count++;
		}
	}

	if (flag) {
		cout << "0" << endl;
		return 0;
	}

	cout << count << endl;
	for (int i = 0; i < count; i++) {
		for (int k = 0; k < result[i].size(); k++) {
			cout << result[i][k] << " ";
		}
		cout << endl;
	}

	return 0;
}