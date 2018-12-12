#include <iostream>
using namespace std;

char rect(int a, int b, int c, int d, int p, int q, int r, int s)
{
	/* case 'a' */
	/*if (p >= a && q >= b && p < c && q < d)	return 'a';
	if (r <= c && s <= d && r > a && s > b)	return 'a';
	if (p >= a && q <= b && s >= d)	return 'a';
	if (q <= b && r <= c && s >= d)	return 'a';
	
	if (p <= a && q <= b && r >= c && s >= d)	return 'a';*/

	/* case 'c' */
	if (a == r && b == s)	return 'c';
	if (c == p && d == q)	return 'c';
	if (a == r && d == q)	return 'c';
	if (b == s && c == p)	return 'c';

	/* case 'd' */
	if (p > c)	return 'd';
	if (q > d)	return 'd';
	if (r < a)	return 'd';
	if (s < b)	return 'd';

	/* case 'b' */
	if (s == b)	return 'b';
	if (r == a) return 'b';
	if (q == d)	return 'b';
	if (p == c)	return 'b';

	return 'a';
}

int main()
{
	int a, b, c, d;
	int p, q, r, s;

	for (int t = 0; t < 4; t++)
	{
		cin >> a >> b >> c >> d;
		cin >> p >> q >> r >> s;

		cout << rect(a, b, c, d, p, q, r, s) << endl;
	}

	return 0;
}