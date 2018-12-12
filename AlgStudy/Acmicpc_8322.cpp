#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;
	int K, N;
	int x1, y1, x2, y2;
	int x, y;

	cin >> T;
	while (T--)
	{
		cin >> K >> N;
		cin >> x1 >> y1 >> x2 >> y2;

		if ((K == 1 && N == 0) || (K == 0 && N == 1)) {
			cout << "TAK" << endl;
			continue;
		}
		x = x2 - x1;
		y = y2 - y1;

		x = x < 0 ? -x : x;
		y = y < 0 ? -y : y;
		
		int num = K - N;
		num = num < 0 ? -num : num;
		/*if (num == 0)
			num = 2;

		if ((x + y) % num == 0)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;*/

		if (x == 0 && y == 0) {
			cout << "TAK" << endl;
			continue;
		}
		if (x == 0 || y == 0) {
			if (K != 0 || N != 0) {
				cout << "NIE" << endl;
				continue;
			}
		}

		if ((x%K == 0 && y%N == 0) || (x%N == 0 && y%K == 0)) {
			cout << "TAK" << endl;
		}
		else if ((x % (K + N) == 0 && y % (K + N) == 0)) {
			cout << "TAK" << endl;
		}
		else
			cout << "NIE" << endl;
	}

	return 0;
}