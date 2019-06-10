#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > conference;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first < b.first)
	{
		return true;
	}
	else if (a.first == b.first)
	{
		if (a.second < b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	
	int start, end;
	while (N--)
	{
		cin >> start >> end;
		conference.push_back(make_pair(start, end - start));
	}

	sort(conference.begin(), conference.end(), compare);

	int conf_cnt = 0;
	int remain_time = 0;
	int prev_time = 0;
	for (auto k : conference)
	{
		remain_time = remain_time - (k.first - prev_time);
		prev_time = k.first;

		if (remain_time > k.second) {
			remain_time = k.second;
			// conf_cnt--;
			// conf_cnt++;		//하는거랑 같음
		}
		else if (remain_time <= 0) {
			remain_time = k.second;
			prev_time = k.first;

			conf_cnt++;
		}
	}

	cout << conf_cnt;

	return 0;
}