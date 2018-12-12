#include <iostream>
using namespace std;

int space[1000];
int clu;

int main()
{
	int N;
	long long cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> space[i];
	}
	cin >> clu;

	for (int i = 0; i < N; i++) {
		if (space[i] == 0) {
			continue;
		}
		if ((space[i]) % clu != 0) {
			cnt += space[i] / clu;
			cnt++;
		}
		else {
			cnt += space[i] / clu;
		}
	}
	long long result;
	result = cnt * clu;
	cout << result << endl;

	return 0;
}