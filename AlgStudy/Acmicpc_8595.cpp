#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	stack<long long> stk;
	int N;
	long long tmp = 0;
	long long result = 0;
	char ch;
	bool flag;

	scanf("%d", &N);

	flag = false;
	getchar();
	for (int i = 0; i < N; ++i) {
		scanf("%c", &ch);
		if (ch - '0' >= 0 && ch - '0' <= 9) {
			if (flag) {
				tmp = 10 * (stk.top());
				stk.pop();
				tmp += ch - '0';
				stk.push(tmp);
			}
			else {
				stk.push(ch - '0');
				flag = true;
			}
		}
		else {
			flag = false;
		}
	}
	int size = stk.size();
	for (int i = 0; i < size; ++i) {
		result += stk.top();
		stk.pop();
	}
	printf("%lld\n", result);

	return 0;
}