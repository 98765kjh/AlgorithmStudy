#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int N, K;
string input;
int code[1000][30];

int src, dst;

vector<int> list[1000];

int calc(int a[], int b[])
{
	int distance = 0;
	for (int i = 0; i < K; i++)
	{
		if (a[i] != b[i])
			distance++;
	}
	return distance;
}

int dfs(int src, int dst)
{
	stack<int> min;
	stack<int> stack;
	vector<int> result;
	bool ischecked[1000];
	int size = 1000;
	int vertex;
	
	for (int i = 0; i < N; i++)
		ischecked[i] = false;

	stack.push(src);
	ischecked[src] = true;

	while (!stack.empty())
	{
		vertex = stack.top();
		for (int i = 0; i < list[vertex].size(); i++)
		{
			int tmp = list[vertex][i];
			if (!ischecked[tmp])
			{
				stack.push(tmp);
				ischecked[tmp] = true;
				if (tmp == dst)
				{
					if (stack.size() < size)
					{
						min = stack;
						size = stack.size();
					}
				}
				break;
			}
			if (i == list[vertex].size() - 1)
			{
				stack.pop();
			}
		}
		
	}

	size = min.size();
	if (size == 0)	return-1;
	for (int i = 0; i < size; i++)
	{
		result.push_back(min.top());
		min.pop();
	}
	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int k = 0; k < K; k++)
			code[i][k] = input[k] - '0';
	}

	cin >> src >> dst;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (calc(code[i], code[j]) == 1)
			{
				list[i].push_back(j);
				list[j].push_back(i);
			}
		}
	}

	
	
	if (dfs(src - 1, dst - 1) == -1)
	{
		cout << "-1" << endl;
	}
	
	return 0;
}