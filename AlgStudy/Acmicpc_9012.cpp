#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	stack<char> stk;

	int T;
	bool isVPS;

	cin >> T;
	while (T--)
	{
		stack<char> stk_clear;
		stk.swap(stk_clear);
		isVPS = true;

		cin >> str;
		for (auto ch : str)
		{
			if (ch == '(') {
				stk.push('(');
			}
			else if (!stk.empty()) {
				stk.pop();
			}
			else {
				isVPS = false;
				break;
			}
		}

		if (!stk.empty())	isVPS = false;

		if (isVPS)	cout << "YES\n";
		else		cout << "NO\n";
	}
}