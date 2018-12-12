#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string num;
	int digroot, tmp;
	int mul;

	while (1) {
		cin >> num;
		if (num == "0")
			break;
		
		digroot = 0;

		for (int i = 0; i < num.size(); i++)
			digroot += num[i] - '0';
		
		/*
			추가) mod 9 를 하면 원하는 값이 나옴.
		*/

		while (digroot / 10 != 0) {
			tmp = 0;
			mul = 1000;
			for (int i = 0; i < 4; i++) {
				tmp += digroot / mul;
				digroot %= mul;
				mul /= 10;
			}
			digroot = tmp;
		}
		cout << digroot << endl;

	}

	return 0;
}