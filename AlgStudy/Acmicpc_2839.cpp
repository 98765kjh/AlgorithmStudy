#include <iostream>
using namespace std;

int main()
{
	int mem;
	int sum;
	int a, b;

	cin >> sum;

	mem = sum;

	b = sum / 5;
	sum = sum % 5;

	while (sum % 3 != 0) {
		if (mem == sum) {
			cout << "-1" << endl;
			return 0;
		}
		sum += 5;
		b--;
	}

	a = sum / 3;
	cout << a + b << endl;

	return 0;
}