#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int len;
	string str, temp;
	int cnt = 0;

	cin >> str;

	len = str.length();
	
	for (int i = 0; i < str.size(); i++) {
		temp = str.substr(i, str.size() - i);
		bool flag = true;
		for (int j = 0; j < temp.size() / 2; j++) {
			if (temp[j] != temp[temp.size() - 1 - j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt = i;
			break;
		}
	}
	cout << temp.size() + cnt * 2 << endl;

	return 0;
}