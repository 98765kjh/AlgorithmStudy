#include <iostream>
using namespace std;

#define num 8
#define time 210

int main()
{
	ios::sync_with_stdio(false);

	int K, N;
	int ask[100];
	bool isclear[100];
	char ch;

	int man;
	int tsize;

	cin >> K >> N;
	
	// 초기화
	man = K;
	tsize = 0;
	for (int i = 0; i < N; i++)
		isclear[i] = false;
	// 입력
	for (int i = 0; i < N; i++) {
		cin >> ask[i] >> ch;
		if (ch == 'T')
			isclear[i] = true;
	}

	for (int i = 0; i < N; i++) {
		tsize += ask[i];

		if (tsize >= time)
			break;

		if (isclear[i]) {
			man++;
			if (man > 8)
				man = 1;
		}
	}

	cout << man << endl;

	return 0;
}