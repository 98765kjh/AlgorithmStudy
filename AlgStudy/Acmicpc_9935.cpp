#include <iostream>
#include <string>
using namespace std;

char stack[10000000];
int pos;
int j, k;

int main()
{
	ios::sync_with_stdio(false);

	string str;
	string boom;

	int str_ed, boom_ed;
	int str_size, boom_size;

	cin >> str;
	cin >> boom;

	str_size = str.size();
	boom_size = boom.size();

	str_ed = str_size - 1;
	boom_ed = boom_size - 1;

	pos = 0;
	for (int i = 0; i < str_size; i++){
		stack[pos++] = str[i];
		if (pos >= boom_size && str[i] == boom[boom_ed]) {
			for (j = pos-1, k = boom_size - 1; k >= 0; j--, k--) {
				if (stack[j] != boom[k])	break;
			}
			if (k == -1)
				pos -= boom_size;
		}
	}
	if (pos == 0)
		cout << "FRULA" << endl;
	else {
		for (int i = 0; i < pos; i++)
			cout << stack[i];
		cout << endl;
	}

	return 0;
}