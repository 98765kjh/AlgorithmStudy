#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > vec;
//bool ischeck[101];

typedef unsigned int uint;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	int a, b;
	int max;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end());

	max = 0;
	int tmax;
	int x1, x2, y1, y2;

	for (uint i = 0; i < vec.size()-1; i++) {
		tmax = 1;
		x1 = vec[i].first;
		x2 = vec[i].second;

		for (uint k = i+1; k < vec.size(); k++) {
			y1 = vec[k].first;
			y2 = vec[k].second;

			if (x1 < y1 && y1 < x2) {
				if (x1 < y2 && y2 < x2)
					tmax++;
			}
			else if (y1 < x1 || x2 < y1) {
				if (y2 < x1 || x2 < y2)
					tmax++;
			}
		}

		if (max < tmax)
			max = tmax;
	}

	cout << max << endl;

	return 0;
}