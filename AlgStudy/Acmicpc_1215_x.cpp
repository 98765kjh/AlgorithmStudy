#include <iostream>
using namespace std;

inline int wrong(int n, int k)
{
	int r = 0;
	for (int i = 1; i <= n; i++)
		r = r + (k%i);
	if (n>k)
		r += k*(n - k);
	return r;
}
int correct(int n, int k)
{
	int r = 0;
	for (int i = 1; i <= k; i++)
		r = (r + k) % i;
	return r;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << wrong(n, k) << endl;
	return 0;
}