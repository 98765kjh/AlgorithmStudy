#include <iostream>
using namespace std;

int Start, End;
struct str
{
	int time;
	int cnt;
};

str cache[200000];

int main()
{
	ios::sync_with_stdio(false);
	int cnt, pos;

	cin >> Start >> End;

	if (End <= Start) {
		cout << Start - End << endl;
		cout << "1" << endl;
		return 0;
	}

	// 초기화
	for (int i = 1; i <= End; i++)
		cache[i].time = 999999;

	for (int i = 0; i <= Start; i++)
	{
		cache[i].time = Start - i;
		cache[i].cnt = 1;
	}
	for (int i = Start; i <= Start * 2; i++)
	{
		cache[i].time = i - Start;
		cache[i].cnt = 1;
	}

	int len = 5;
	int before = 1;
	for (len; len <= 100000; len = len * 2) {
		for (int pos = before; pos <= len; pos++) {
			// 2배
			if (cache[pos].time + 1 < cache[pos * 2].time) {
				cache[pos * 2].time = cache[pos].time + 1;
				cache[pos * 2].cnt = 1;
			}
			else if (cache[pos].time + 1 == cache[pos * 2].time)
				cache[pos * 2].cnt++;
			// 2배 뒤
			if (cache[pos].time + 2 < cache[pos * 2 - 1].time) {
				cache[pos * 2 - 1].time = cache[pos].time + 2;
				cache[pos * 2 - 1].cnt = 1;
			}
			else if (cache[pos].time + 2 == cache[pos * 2 - 1].time)
				cache[pos * 2 - 1].cnt++;
			// 2배 앞
			if (cache[pos].time + 2 < cache[pos * 2 + 1].time) {
				cache[pos * 2 + 1].time = cache[pos].time + 2;
				cache[pos * 2 + 1].cnt = 1;
			}
			else if (cache[pos].time + 2 == cache[pos * 2 + 1].time)
				cache[pos * 2 + 1].cnt++;

		}
		before = len;
	}
	
	cout << cache[End].time << endl;
	cout << cache[End].cnt << endl;


	return 0;
}