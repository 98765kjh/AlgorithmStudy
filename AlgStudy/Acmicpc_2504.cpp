#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> stk;

int main()
{
	string str, tmp;
	int result, num;
	bool isFail = false;

	result = 0;

	cin >> str;
	for (auto ch : str)
	{
		switch (ch)
		{
		case '(':
			stk.push("(");
			break;
		case '[':
			stk.push("[");
			break;
		case ')':
			if (stk.empty())
			{
				isFail = true;
			}
			else
			{
				tmp = stk.top();
				stk.pop();
				if (tmp == "(") {
					stk.push(to_string(2));
				}
				else if (tmp == "[") {
					isFail = true;
				}
				else {
					num = atoi(tmp.c_str());
					if (stk.empty())
					{
						isFail = true;
					}
					else
					{
						while (!stk.empty())
						{
							tmp = stk.top();
							stk.pop();
							if (tmp == "(") {
								num = num * 2;
								break;
							}
							else if (tmp == "[") {
								isFail = true;
							}
							else {
								num = num + atoi(tmp.c_str());
							}
						}
						stk.push(to_string(num));
					}
				}
			}
			break;
		case ']':
			if (stk.empty())
			{
				isFail = true;
			}
			else
			{
				tmp = stk.top();
				stk.pop();
				if (tmp == "[") {
					stk.push(to_string(3));
				}
				else if (tmp == "(") {
					isFail = true;
				}
				else {
					num = atoi(tmp.c_str());
					if (stk.empty())
					{
						isFail = true;
					}
					else
					{
						while (!stk.empty())
						{
							tmp = stk.top();
							stk.pop();
							if (tmp == "[") {
								num = num * 3;
								break;
							}
							else if (tmp == "(") {
								isFail = true;
							}
							else {
								num = num + atoi(tmp.c_str());
							}
						}
						stk.push(to_string(num));
					}
				}
			}
			break;
		}

		if (isFail)
		{
			result = 0;
			break;
		}
	}
	if (!isFail)
	{
		result = 0;
		while (!stk.empty())
		{
			tmp = stk.top();
			stk.pop();
			if (tmp == "(" || tmp == ")" || tmp == "[" || tmp == "]") {
				result = 0;
				break;
			}
			else {
				result = result + atoi(tmp.c_str());
			}
		}
	}
	cout << result << endl;

	return 0;
}