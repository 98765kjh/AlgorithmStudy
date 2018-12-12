#include <iostream>
using namespace std;

struct str
{
	int icurr;
	int inext;
	int belt;
};
int main()
{
	ios::sync_with_stdio(false);
	str B[1000];
	int M;
	long long result = 1;

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i].icurr >> B[i].inext >> B[i].belt;
	}

	bool flag = true;
	for (int i = 0; i < M; i++) {

		if (B[i].belt == 0) {
			result *= B[i].inext;
			result /= B[i].icurr;
		}
		else {
			result *= B[i].inext;
			result /= B[i].icurr;
			if (flag)
				flag = false;
			else
				flag = true;
		}
	}
	int dir;
	if (flag)
		dir = 0;
	else
		dir = 1;
	cout << dir << " " << result << endl;

	return 0;
}