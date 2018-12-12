#include <iostream>
#include <algorithm>
using namespace std;

struct st
{
	int num;
	int org;
};

bool comp(st a, st b)
{
	return a.num < b.num;
}
int main()
{
	ios::sync_with_stdio(false);

	int N;
	st num[100000];

	cin >> N;

	int tmin, min;
	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> num[i].org;
		num[i].num = num[i].org < 0 ? -num[i].org : num[i].org;
	}

	sort(num, num + N, comp);

	int pos;
	min = 1111111111;
	for (int i = 0; i < N - 1; i++) {
		tmin = num[i].org + num[i + 1].org;
		tmin = tmin < 0 ? -tmin : tmin;
		if (tmin < min) {
			min = tmin;
			pos = i;
		}
	}

	if (num[pos].org < num[pos + 1].org) {
		cout << num[pos].org << " " << num[pos + 1].org << endl;
	}
	else {
		cout << num[pos + 1].org << " " << num[pos].org << endl;
	}

	return 0;
}