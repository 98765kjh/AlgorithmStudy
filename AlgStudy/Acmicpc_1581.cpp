#include <iostream>
using namespace std;

int main()
{
	int ff, fs, sf, ss;
	ff = fs = sf = ss = 0;

	cin >> ff >> fs >> sf >> ss;

	if (ff == 0) {
		if (fs == 0) {
			if (sf == 0)
				cout << ss << endl;
			else
				cout << ss + 1 << endl;

			return 0;
		}
		else {
			if (fs > sf) {
				cout << sf * 2 + ss + 1 << endl;
			}
			else {
				cout << fs * 2 + ss << endl;
			}

			return 0;
		}
	}
	if (ff != 0) {
		if (fs == 0) {
			cout << ff << endl;
			return 0;
		}
		else {
			if (sf==0) {
				cout << ff + 1 + ss << endl;
				return 0;
			}
			else {
				if (ss == 0) {
					if (fs > sf) {
						cout << ff + sf * 2 + 1 << endl;
					}
					else {
						cout << ff + fs * 2 << endl;
					}

					return 0;
				}
				else {
					if (fs > sf) {
						cout << ff + sf * 2 + ss + 1 << endl;
					}
					else {
						cout << ff + fs * 2 + ss << endl;
					}

					return 0;
				}
			}
		}
	}

	return 0;
}