#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> stk;
vector<char> operator_arr;

void pop()
{
	stk.pop();
	operator_arr.push_back('-');
}
void push(int i)
{
	stk.push(i);
	operator_arr.push_back('+');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, target, now;

	cin >> T;
	now = 1;
	while (T--)
	{
		cin >> target;
		
		while (!stk.empty())
		{
			if (stk.top() > target) {	// Impossible
				cout << "NO\n";
				return 0;
			}
			else {
				break;
			}
		}

		for (int i = now; i <= target; i++) {
			push(i);
			now++;
		}
		pop();
	}

	for (auto k : operator_arr)
		cout << k << "\n";

	return 0;
}