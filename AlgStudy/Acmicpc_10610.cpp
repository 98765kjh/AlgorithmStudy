#include <iostream>
#include <string>
using namespace std;

string numstr;
int counting[10];

int main()
{
	cin >> numstr;

	int sum = 0;
	bool has_zero = false;
	for (int i = 0; i < numstr.length(); i++)
	{
		int number = numstr[i] - '0';
		sum = sum + (number);
		counting[number]++;
		if (numstr[i] == '0')
			has_zero = true;
	}

	if (!has_zero || sum % 3 != 0) {
		cout << "-1";
	}
	else {
		for (int i = 9; i >= 0; i--) {
			while (counting[i]) {
				cout << i;
				counting[i]--;
			}
		}
	}

	return 0;
}