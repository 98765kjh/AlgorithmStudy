#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<pii> arr;
vector<pii> ans;
int lis[100002];
bool visit[500002];

bool compareB(pii a, pii b)
{
	return a.second < b.second;
}

int _lower_bound(int arr[], int target, int size)
{
	int start, mid, end;
	start = 0; end = size - 1;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (arr[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main()
{
	int N;
	int a, b;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);

		arr.push_back({ a,b });
		visit[a] = true;
	}
	sort(arr.begin(), arr.end());

	ans.push_back({ 0,arr[0].first });
	int lis_pos = 0;
	lis[0] = arr[0].second;

	for (int arr_pos = 1; arr_pos < N; arr_pos++) {
		if (lis[lis_pos] < arr[arr_pos].second) {
			lis[++lis_pos] = arr[arr_pos].second;
			ans.push_back({ lis_pos,arr[arr_pos].first });
		}
		else {
			int bound_pos = _lower_bound(lis, arr[arr_pos].second, lis_pos + 1);
			lis[bound_pos] = arr[arr_pos].second;
			ans.push_back({ bound_pos,arr[arr_pos].first });
		}
	}

	int t = lis_pos;

	printf("%d\n", N - (t + 1));

	for (int i = N - 1; i >= 0; i--) {
		if (ans[i].first == t) {
			visit[ans[i].second] = false;
			t--;
		}
	}

	for (int i = 0; i < 500002; i++) {
		if (visit[i])
			printf("%d\n", i);
	}

	return 0;
}