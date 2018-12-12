#include <stdio.h>
#include <algorithm>
using namespace std;

//int addcalc[5000][5000];

bool isPos[5000];
int calc[5000][5000];

int main()
{
	int arr[5000];
	int N;
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			addcalc[i][j] = arr[i] + arr[j];
		}*/

	/*for (int i = 0; i < N; i++)
		if (arr[i] % 3 == 0)
			for (int j = 0; j < i; j++)
				if (arr[j] == arr[i] / 3)
				{
					isPos[i] = true;
					break;
				}*/

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		printf("%d\t", addcalc[i][j]);
	//	}
	//	printf("\n");
	//}

	for (int T = 0; T < N; T++) {
		/*if (isPos[T])
		{
			cnt++;
			continue;
		}*/
		for (int i = 0; i <= T; i++)
			calc[T][i] = arr[T] - arr[i];
		
		for (int i = 0; i < T; i++) {
			for (int j = i; j < T; j++) {
				

				for (int v = 0; v <= T; v++) {
					if (arr[i]+arr[j] == calc[T][v]) {
						j = T; i = T;		// Å»Ãâ
						cnt++;
						break;
					}
				}
			}
		}

	}

	printf("%d\n", cnt);

	return 0;
}