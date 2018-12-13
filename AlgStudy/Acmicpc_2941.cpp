#include <iostream>
#include <string>
using namespace std;

int findCroatian(string S, int pos)
{
	string str;
	if (S.at(pos) == 'd') {
		str = S.substr(pos, 3);
		if (str == "dz=") {
			return 3;
		}
		else if (str.substr(0, 2) == "d-") {
			return 2;
		}
	}
	else {
		str = S.substr(pos, 2);
		if (str=="c=" || str=="c-" || str=="d-" || str=="lj" || str=="nj" || str=="s=" || str=="z=") {
			return 2;
		}
	}
	return 0;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string S;
	int cnt = 0;
	int isCroatian = 0;

	cin >> S;
	
	for (int i = 0; i < S.length(); ) {
		isCroatian = findCroatian(S, i);
		if (!isCroatian) {
			i = i + 1;
		}
		else {
			i = i + isCroatian;
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}