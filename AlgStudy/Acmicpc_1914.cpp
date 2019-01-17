#include <iostream>
using namespace std;

unsigned long long int dp[101] = { 0,1 };

//
// big integer 구현 문제라서 파이썬으로 제출함.
//
// python3 code

/*
dp = [0, 1]
for i in range(2,100):
	dp.append(dp[i-1]*2 + 1)

def hanoi(height, start, end):
	mid = 6-start-end
	if height == 1:
		print (start, end)
	else:
		hanoi(height-1, start, mid)
		print (start, end)
		hanoi(height-1, mid, end)

N = int(input())
print (dp[N])
if N<=20:
	hanoi(N, 1, 3)
*/


void Init(int height)
{
	for (int i = 2; i <= height; i++)
	{
		dp[i] = dp[i - 1] * 2 + 1;
	}
}
void hanoi(int height, int start, int end)
{
	int mid = 6 - start - end;
	if (height == 1)
	{
		printf("%d %d\n", start, end);
	}
	else
	{
		hanoi(height - 1, start, mid);
		printf("%d %d\n", start, end);
		hanoi(height - 1, mid, end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	// initialize
	Init(100);

	// input / output
	cin >> N;
	cout << dp[N] << '\n';

	// if N is under 20, print process
	if (N <= 20)
		hanoi(N, 1, 3);

	return 0;
}