#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int apt[300001];		// 건물 높이
bool istrp[300001];		// 트램펄린 있는 위치
bool ischecked[300001];

typedef struct _str
{
	int start, end;
	int size;
}str;

bool comp(str a, str b)
{
	return a.size > b.size;
}

int main()
{
	ios::sync_with_stdio(false);

	int N, K;
	string s;

	vector<str> trpG;		// 트램펄린 그룹
	vector<str> norG;		// 노멀 그룹
	vector<str> lG, rG;		// left, right 그룹

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> apt[i];
	cin >> s;
	for (int i = 0; i < N; i++)
	{
		if (s[i] == '.')	istrp[i+1] = false;
		else			istrp[i+1] = true;
	}

	int lcnt = 1, rcnt = 1;
	bool flag = false;
	// 트램펄린을 만나지 못하는 경우
	if (istrp[K])	flag = true;
	for (int i = K; i > 1; i--)
	{
		if (apt[i] >= apt[i - 1])
		{
			lcnt++;
			if (istrp[i - 1])	flag = true;
		}
		if (flag)
			break;
	}
	for (int i = K; i < N; i++)
	{
		if (apt[i] >= apt[i + 1])
		{
			rcnt++;
			if (istrp[i + 1])	flag = true;
		}
		if (flag)
			break;
	}
	for (int i = K; i < N; i++)
	{
		if (apt[i] == apt[i + 1])
		{
			lcnt++;
		}
		else
			break;
	}
	for (int i = K; i > 1; i--)
	{
		if (apt[i] == apt[i - 1])
		{
			rcnt++;
		}
		else
			break;
	}
	if (!flag)
	{
		int result = 0;
		result = (lcnt > rcnt) ? lcnt : rcnt;
		cout << result << endl;
		return 0;
	}

	// 시작점부근에 트램펄린이 있는 경우
	str tmp;
	tmp.start = 1;
	tmp.size = 1;
	for (int i = 1; i <= N; i++)
	{
		if (i == N)
		{
			tmp.end = i;
			norG.push_back(tmp);
			break;
		}
		if (apt[i] >= apt[i + 1])
		{
			tmp.size++;
		}
		else
		{
			tmp.end = i;
			norG.push_back(tmp);

			tmp.start = i + 1;
			tmp.size = 1;
		}
	}

	for (int i = 0; i < norG.size(); i++)
	{
		tmp.start = norG[i].start;

		for (int k = norG[i].start; k <= norG[i].end; k++)
		{
			if (istrp[k])
			{
				tmp.end = k;
				tmp.size = tmp.end - tmp.start + 1;
				trpG.push_back(tmp);

				tmp.start = k + 1;
			}
		}
	}
	
	// 트램펄린 그룹 체크
	for (int k = 0; k < trpG.size(); k++)
		for (int i = trpG[k].start; i <= trpG[k].end; i++)
			ischecked[i] = true;
	
	for (int k = 0; k < trpG.size(); k++)
	{
		for (int i = trpG[k].end; i <= N; i++)
		{
			if (!ischecked[i + 1] && apt[i] < apt[i+1])
			{
				trpG[k].end++;
				trpG[k].size++;
				ischecked[i + 1] = true;
			}
			else break;
		}
	}
	
	norG.clear();

	// 왼쪽 -> 오른쪽으로의 그룹
	tmp.start = 1;
	for (int i = 1; i <= N; i++)
	{
		if (i == N && !ischecked[i])
		{
			tmp.end = i;
			tmp.size = tmp.end - tmp.start + 1;
			lG.push_back(tmp);
			break;
		}
		if (ischecked[i])
		{
			tmp.start = i + 1;
			continue;
		}
		if (apt[i] < apt[i + 1])
		{
			tmp.end = i;
			tmp.size = tmp.end - tmp.start + 1;
			lG.push_back(tmp);
			tmp.start = i + 1;
		}
	}

	// 오른쪽 -> 왼쪽으로의 그룹
	tmp.start = N;
	for (int i = N; i >= 1; i--)
	{
		if (i == 1 && !ischecked[i])
		{
			tmp.end = i;
			tmp.size = tmp.start - tmp.end + 1;
			rG.push_back(tmp);
			break;
		}
		if (ischecked[i])
		{
			tmp.start = i - 1;
			continue;
		}
		if (apt[i] < apt[i - 1])
		{
			tmp.end = i;
			tmp.size = tmp.start - tmp.end + 1;
			rG.push_back(tmp);
			tmp.start = i - 1;
		}
	}

	sort(lG.begin(), lG.end(), comp);
	sort(rG.begin(), rG.end(), comp);
/*
	cout << "----- Tramp Group -----" << endl;
	for (int i = 0; i < trpG.size(); i++)
	{
		cout << trpG[i].start << " " << trpG[i].end << " -> " << trpG[i].size << endl;
	}
	cout << "----- l Group -----" << endl;
	for (int i = 0; i < lG.size(); i++)
	{
		cout << lG[i].start << " " << lG[i].end << " -> " << lG[i].size << endl;
	}
	cout << "----- r Group -----" << endl;
	for (int i = 0; i < rG.size(); i++)
	{
		cout << rG[i].start << " " << rG[i].end << " -> " << rG[i].size << endl;
	}*/
	
	int sum = 0;
	
	for (int i = 0; i < trpG.size(); i++)
		sum += trpG[i].size;
	
	if (rG.empty() && lG.empty())
	{
		cout << sum << endl;
		return 0;
	}
	if (rG.empty())
	{
		cout << sum+lG[0].size << endl;
		return 0;
	}
	if (lG.empty())
	{
		cout << sum+rG[0].size << endl;
		return 0;
	}

	sum += (rG[0].size > lG[0].size) ? rG[0].size : lG[0].size;

	cout << sum << endl;

	return 0;
}