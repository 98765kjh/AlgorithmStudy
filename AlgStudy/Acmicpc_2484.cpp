#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	int result;
	int max;

	int tmp[7];
	int num[4];
	int flag, pos, pos2;

	cin >> N;

	max = 0;

	for (int t = 0; t < N; t++) {
		// 초기화
		for (int i = 0; i < 7; i++)
			tmp[i] = 0;
		flag = 5;

		// 입력
		for (int i = 0; i < 4; i++) {
			cin >> num[i];
			tmp[num[i]]++;
		}

		// 케이스 계산
		for (int i = 1; i < 7; i++) {
			if (tmp[i] == 4) {
				flag = 1;
				pos = i;
				break;
			}
			else if (tmp[i] == 3) {
				flag = 2;
				pos = i;
				break;
			}
			else if (tmp[i] == 2) {
				pos = i;

				for (int k = i + 1; i < 7; i++) {
					if (tmp[k] == 2) {
						flag = 3;
						pos2 = k;
						break;
					}
				}
				if (flag == 3) {
					break;
				}
				else {
					flag = 4;
					break;
				}
			}
		}


		if (flag == 1) {
			result = 50000 + pos * 5000;
		}
		else if (flag == 2) {
			result = 10000 + pos * 1000;
		}
		else if (flag == 3) {
			result = 2000 + pos * 500 + pos2 * 500;
		}
		else if (flag == 4) {
			result = 1000 + pos * 100;
		}
		else {
			for (int k = 6; k > 0; k--) {
				if (tmp[k]) {
					result = k * 100;
					break;
				}
			}
		}

		if (result > max)
			max = result;
	}

	cout << max << endl;

	return 0;
}