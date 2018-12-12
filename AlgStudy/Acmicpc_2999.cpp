#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string str;
	char ch[101];
	int size = 0, cnt = 0;
	int i;
	int div[30];

	cin >> str;

	size = str.length();

	// 약수 구하기
	div[0] = 1;
	cnt = 1;
	for (i = 2; i*i < size; i++) {
		if (size % i)   continue;
		div[cnt] = i;
		cnt++;
	}

	if (i*i == size) {
		div[cnt] = i;
		cnt++;
	}
	int num = cnt;
	for (i = 1; i <= num; i++) {
		if (size % div[num - i])   continue;
		if (div[cnt - 1] == size / div[num - i])
			continue;
		div[cnt] = size / div[num - i];
		cnt++;
	}
	
	// R, C 찾기
	int R, C;
	for (int i = cnt - 1; i >= 0; i--) {
		R = div[i];
		C = size / R;
		if (R <= C) break;
	}

	if (R == 1) {
		cout << str << endl;
		return 0;
	}

	memset(ch, '0', R*C-1);

	int n = 0;
	for (int i = 0; i < C; i++) {
		for (int k = 0; k < R; k++) {
			ch[i + k*C] = str[n];
			n++;
		}
	}
	ch[R*C] = NULL;
	cout << ch << endl;

	return 0;
}