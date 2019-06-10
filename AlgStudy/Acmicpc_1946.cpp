#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector< pair<int, int> > employee;
vector< pair<int, int> > selected;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int N;

	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			pair<int, int> man;

			cin >> man.first >> man.second;

			employee.push_back(man);
		}

		sort(employee.begin(), employee.end(), compare);


		selected.push_back(employee[0]);

		int pos = 0;
		for (int i = 1; i < employee.size(); i++)
		{
			if (employee[i].second < selected[pos].second) {
				selected.push_back(employee[i]);
				pos++;
			}
		}

		cout << selected.size() << endl;

		employee.clear();
		selected.clear();
	}

	return 0;
}