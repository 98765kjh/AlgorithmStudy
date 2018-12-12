#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main()
{
	int N;
	int num, h;
	list<int> blue;
	list<int> white;
	bool ishate[101];

	queue<int> que;
	bool bluewhite[101];
	bool ischeck[101];

	list<int> hate[101];

	cin >> N;
	for (int i = 0; i <= 100; i++)
		ishate[i] = false;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int k = 0; k < num; k++) {
			cin >> h;
			hate[i + 1].push_back(h);
			hate[h].push_back(i + 1);
		}
	}

	for (int i = 1; i <= N; i++) {
		hate[i].sort();
		hate[i].unique();
	}

	for (int i = 0; i <= 100; i++)
		ischeck[i] = false;
	list<int>::iterator it;

	for (int i = 1; i <= N; i++)
	{
		if (ischeck[i])
			continue;
		ischeck[i] = true;
		bluewhite[i] = false;
		que.push(i);
		blue.push_back(i);
		int top;
		while (!que.empty()) {
			top = que.front();
			for (it = hate[top].begin(); it != hate[top].end(); it++) {
				if (!ischeck[*it]) {
					if (bluewhite[top]) {
						ischeck[*it] = true;
						blue.push_back(*it);
						que.push(*it);
						bluewhite[*it] = false;

					}
					else {
						ischeck[*it] = true;
						white.push_back(*it);
						que.push(*it);
						bluewhite[*it] = true;
					}
				}
			}

			que.pop();
		}
	}

	blue.sort();
	white.sort();
	
	cout << blue.size() << endl;
	for (it = blue.begin(); it != blue.end(); it++)
		cout << *it << " ";
	cout << endl << white.size() << endl;
	for (it = white.begin(); it != white.end(); it++)
		cout << *it << " ";
	cout << endl;


	return 0;
}