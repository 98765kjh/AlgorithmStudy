#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	int N;

	cin >> N;

	while (N--) {
		cin >> A >> B;
		cout << A + B << '\n';
	}
}