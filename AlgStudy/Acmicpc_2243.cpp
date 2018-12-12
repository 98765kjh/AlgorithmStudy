#include <stdio.h>
#include <set>
using namespace std;

#define MAX 1000001

set<int> sweet;
int s_num[MAX];

int main()
{
	int N;
	int A, B, C;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		if (A == 1) {
			scanf("%d", &B);
			int tmp = 0;
			for (set<int>::iterator it = sweet.begin(); it != sweet.end(); it++) {
				tmp += s_num[*it];
				if (tmp >= B) {
					printf("%d\n", *it);
					s_num[*it]--;
					if (s_num[*it] == 0)
						sweet.erase(*it);
					break;
				}
			}
		}
		else {
			scanf("%d%d", &B, &C);
			s_num[B] += C;
			if (s_num[B] < 0) {
				s_num[B] = 0;
				sweet.erase(B);
			}
			else {
				sweet.insert(B);
			}
		}
	}
	return 0;
}