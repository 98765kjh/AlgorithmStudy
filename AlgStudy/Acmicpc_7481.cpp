#include <iostream>
using namespace std;

int a, b, S;

int main()
{
	int T;
	int anum, bnum;
	bool flag;
	cin >> T;
	while (T--)
	{
		flag = false;
		cin >> a >> b >> S;
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
			flag = true;
		}
		bnum = S / b;
		for (int i = bnum; i >= 0; i--) {
			anum = (S - i*b) / a;
			if (anum*a + i*b == S) {
				if (flag) {
					cout << i << " " << anum << endl;
					bnum = i;
					break;
				}
				else {
					cout << anum << " " << i << endl;
					bnum = i;
					break;
				}
			}
		}
		if (anum*a + bnum*b != S) {
			cout << "Impossible" << endl;
		}
	}

	return 0;
}