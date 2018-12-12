#include<iostream>
#include <vector>
#include <stack>
using namespace std;

/*
	calc코드는 완전탐색 코드

	이 문제는 fibonacci수열이 양의 정수를 이룰 때 최소의 개수가
	큰 수에서부터 순차적으로 탐색하면 찾을 수 있다는 규칙을 이용하면
	완전탐색 코드를 짜지 않고 O(n)으로 빠르게 찾을 수 있다.
*/
vector<int> fib;
stack<int> tmp;
stack<int> result;
int num;
bool ischecked[46];

int calc(int sum, int pos) {
	if (sum > num) 
		return 1;
	
	for (int i = pos; i > 0; i--) {
		if (!ischecked[pos]) {
			if (sum == num)
				return 0;

			if (sum + fib[i] <= num) {
				sum += fib[i];
				ischecked[i] = true;
				tmp.push(fib[i]);
				if (!calc(sum, i - 1))
					return 0;
				else
				{
					sum -= fib[i];
					ischecked[i] = false;
					tmp.pop();
				}
			}
		}
	}
	return 1;
}

int main()
{
	int T;

	fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);
	for (int i = 3; i < 46; i++) 
		fib.push_back(fib[i - 2] + fib[i - 1]);
	
	cin >> T;
	while (T--) {
		cin >> num;

		/* 기존 완전탐색 코드 */
		/*bool flag;
		flag = false;
		for (int i = 1; i < 46; i++) {
			if (num == fib[i])
			{
				cout << num << endl;
				flag=true;
				break;
			}
		}
		if (flag)
			continue;

		while (!tmp.empty())
			tmp.pop();
		while (!result.empty())
			result.pop();
		for (int i = 0; i < 46; i++)
			ischecked[i] = false;

		int pos = 45;

		for (int i = 2; i < 46; i++) {
			if (num<=fib[i]) {
				pos = i - 1;
				break;
			}
		}
		calc(0, pos);

		while (!tmp.empty()) {
			cout << tmp.top() << " ";
			tmp.pop();
		}
		cout << endl;*/

		/* 순차 탐색 코드 */
		int sum = 0;
		for (int i = 0; i < 46; i++)
			ischecked[i] = false;
		for (int i = 45; i > 0; i--) {
			if (sum == num)
				break;
			else {
				if (sum + fib[i] <= num) {
					sum += fib[i];
					ischecked[i] = true;
				}
			}
		}

		for (int i = 1; i < 46; i++) {
			if (ischecked[i])
				cout << fib[i] << " ";
		}
		cout << endl;
	}
}