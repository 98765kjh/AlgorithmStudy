#include <iostream>
#include <string>
using namespace std;

void hex2binInit(char ch)
{
	switch (ch)
	{
	case '0':
		cout << "0";
		break;
	case '1':
		cout << "1";
		break;
	case '2':
		cout << "10";
		break;
	case '3':
		cout << "11";
		break;
	case '4':
		cout << "100";
		break;
	case '5':
		cout << "101";
		break;
	case '6':
		cout << "110";
		break;
	case '7':
		cout << "111";
		break;
	}
}

void hex2bin(char ch)
{
	switch (ch)
	{
	case '0':
		cout << "000";
		break;
	case '1':
		cout << "001";
		break;
	case '2':
		cout << "010";
		break;
	case '3':
		cout << "011";
		break;
	case '4':
		cout << "100";
		break;
	case '5':
		cout << "101";
		break;
	case '6':
		cout << "110";
		break;
	case '7':
		cout << "111";
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string hex;

	cin >> hex;

	hex2binInit(hex[0]);
	for (int i = 1; i < hex.length(); i++)
	{
		hex2bin(hex[i]);
	}
	return 0;
}