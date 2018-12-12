#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int acnt, bcnt;
	
	acnt = bcnt = 0;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '1')
			acnt++;
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '1')
			bcnt++;
	}

	if (acnt % 2 == 1) {
		if (bcnt <= acnt + 1) 
			cout << "VICTORY" << endl;
		else
			cout << "DEFEAT" << endl;
	}
	else {
		if (acnt >= bcnt)
			cout << "VICTORY" << endl;
		else 
			cout << "DEFEAT" << endl;
	}

	return 0;
}