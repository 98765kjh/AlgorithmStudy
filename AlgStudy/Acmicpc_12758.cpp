#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int T;
int N;
int height[300];
int divi[300][400];
int cnt[300];
int i;

int dp[300][400]; 

int main()
{
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &height[i]);
			divi[i][0] = 1;
			cnt[i] = 1;
		}

		// 약수 구하기
		for (int k = 0; k < N; k++) {
			
			for (i = 2; i*i < height[k]; i++) {
				if (height[k] % i)	continue;
				divi[k][cnt[k]] = i;
				cnt[k]++;
			}

			if (i*i == height[k]) {
				divi[k][cnt[k]] = i;
				cnt[k]++;
			}
			int num = cnt[k];
			for (i = 1; i <= num; i++) {
				if (height[k] % divi[k][num - i])	continue;
				if (divi[k][cnt[k] - 1] == height[k] / divi[k][num - i])
					continue;
				divi[k][cnt[k]] = height[k] / divi[k][num - i];
				cnt[k]++;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int n = 0; n < cnt[i]; n++) {
				dp[i][n] = 0;
			}
		}
		for (int n = 0; n < cnt[0]; n++)
			dp[0][n] = 1;

		for (int i = 0; i < N - 1; i++) {
			for (int a = 0; a < cnt[i]; a++) {
				for (int b = 0; b < cnt[i + 1]; b++) {
					if (divi[i][a] <= divi[i + 1][b]) {
						dp[i + 1][b] += dp[i][a];
						dp[i + 1][b] %= 1000000007;
					}
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < cnt[N - 1]; i++) {
			sum += dp[N - 1][i];
			sum %= 1000000007;
		}
		printf("%d\n", sum);
	}
}