#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	bool cup[4];
	int before, after;
	int M;

	cin >> M;
	
	cup[0] = cup[1] = cup[2] = cup[3] = false;
	cup[1] = true;

	for (int i = 0; i < M; i++) {
		cin >> before >> after;
		if (before != after) {
			if (cup[before]) {
				cup[before] = false;
				cup[after] = true;
			}
			else if (cup[after]) {
				cup[after] = false;
				cup[before] = true;
			}
		}
	}

	for (int i = 1; i < 4; i++) {
		if (cup[i]) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}