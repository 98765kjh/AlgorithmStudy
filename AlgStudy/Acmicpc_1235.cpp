#include <iostream>
#include <string>
using namespace std;

string stud[1000];
bool check[1000];

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> stud[i];
	}
	
	int pos = 1;
	/*for (int i = 0; i < N; ++i)
		check[i] = false;*/

	for (int i = stud[0].length() - 1; i >= 0; --i) {
		int tmp = pos;
		for (int j = 0; j < N - 1; ++j) {
			string tmpstr = stud[j].substr(i, pos);
			for (int k = j + 1; k < N; ++k) {
				if (tmpstr == stud[k].substr(i, pos)) {
					pos++;
					break;
				}
			}
			if (tmp != pos)
				break;
		}
		if (tmp == pos)
			break;
	}

	cout << pos << endl;

	return 0;
}