#include <iostream>
#include <stack>
using namespace std;

stack<int> stk[7];

int main()
{
	ios::sync_with_stdio(false);

	int N, P;
	int num, plat;
	int count = 0;
	int max[7];

	cin >> N >> P;

	for (int i = 0; i < 7; i++)
		max[i] = 0;


	for (int i = 0; i < N; i++) {
		cin >> num >> plat;

		if (max[num] < plat) {
			max[num] = plat;
			count++;
			stk[num].push(plat);
		}
		else if (max[num] == plat) {
			//count++;
		}
		else {
			while (stk[num].top() > plat) {
				stk[num].pop();
				count++;
				if (stk[num].empty()) break;
			}
			if (stk[num].empty()) {
				max[num] = plat;
				count++;
				stk[num].push(plat);
			}
			else {
				if (stk[num].top() == plat) {
					//count++;
					max[num] = plat;
				}
				else {
					max[num] = plat;
					count++;
					stk[num].push(plat);
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}