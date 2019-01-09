#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<8> bs;

	hash<bitset<8>> hash_fun;

	cout << bs << endl;

	bs |= 5;
	cout << bs << endl;
	cout << bs.count() << endl;
	cout << bs.flip() << endl;
	cout << bs << endl;

	
	cout << bs << endl;

	cout << bs.size() << endl;

	cout << hash_fun(bs) << endl;

	return 0;
}