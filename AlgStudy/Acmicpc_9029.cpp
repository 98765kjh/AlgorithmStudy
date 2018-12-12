#include <iostream>
using namespace std;

int dp[201][201][201];
int T;

int cut(int L,int W,int H)
{
	int ret;
	if (L == W && W == H) {
		dp[L][W][H] = 1;
		return 1;
	}
	if (dp[L][W][H] != 0)
		return dp[L][W][H];

	int min;
	if (L <= W && L <= H)
		min = L;
	else if (W <= L && W <= H)
		min = W;
	else
		min = H;

	if (min == 1)
		return L*W*H;
	ret = L*W*H;
	for (int i = 1; i <= L / 2; i++) {
		if (L - i <= 0)	break;
		int tmp = cut(L - i, W, H) + cut(i, W, H);
		if (tmp < ret)
			ret = tmp;
	}
	for (int i = 1; i <= W / 2; i++) {
		if (W - i <= 0)	break;
		int tmp = cut(L, W-i, H) + cut(L, i, H);
		if (tmp < ret)
			ret = tmp;
	}
	for (int i = 1; i <= H / 2; i++) {
		if (H - i <= 0)	break;
		int tmp = cut(L, W, H-i) + cut(L, W, i);
		if (tmp < ret)
			ret = tmp;
	}
	dp[L][W][H] = ret;
	return ret;
}
int main()
{
	int L, W, H;
	cin >> T;
	while (T--) {
		cin >> L >> W >> H;
		cout << cut(L,W,H) << endl;
	}
	return 0;
}