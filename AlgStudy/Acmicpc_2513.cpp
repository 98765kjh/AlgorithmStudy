#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dept
{
	int pos;
	int num;
};

bool comp(const dept &a, const dept &b)
{
	return a.pos < b.pos;
}

int main()
{
	ios::sync_with_stdio(false);

	vector<dept> left, right;
	int N, K, S;
	dept tmp;

	cin >> N >> K >> S;
	for (int i = 0; i < N; ++i) {
		cin >> tmp.pos >> tmp.num;
		if (tmp.pos < S)
			left.push_back(tmp);
		else
			right.push_back(tmp);
	}

	sort(left.begin(), left.end(), comp);
	sort(right.begin(), right.end(), comp);

	int result = 0;
	int tmp_num;

	int idx = 0;

	while(idx<left.size()){
		tmp_num = 0;
		result += S - left[idx].pos;
		while(1) {
			if (idx >= left.size())	break;
			if (tmp_num + left[idx].num <= K) {
				tmp_num += left[idx].num;
				if (idx + 1 >= left.size()) {
					result += S - left[idx].pos;
					idx++;
					break;
				}
				result += left[idx + 1].pos - left[idx].pos;
				idx++;
			}
			else {
				left[idx].num -= K - tmp_num;
				result += S - left[idx].pos;
				break;
			}
		}
	}
	idx = right.size() - 1;
	while (idx >= 0) {
		tmp_num = 0;
		result += right[idx].pos - S;
		while (1) {
			if (idx < 0)	break;
			if (tmp_num + right[idx].num <= K) {
				tmp_num += right[idx].num;
				if (idx - 1 < 0) {
					result += right[idx].pos - S;
					idx--;
					break;
				}
				result += right[idx].pos - right[idx - 1].pos;
				idx--;
			}
			else {
				right[idx].num -= K - tmp_num;
				result += right[idx].pos - S;
				break;
			}
		}
	}

	cout << result << endl;

	return 0;
}