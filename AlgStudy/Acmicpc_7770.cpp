#include <iostream>
using namespace std;

#define MAX 1150
int arr[MAX];

int main()
{
	int num;
	int add = 1;
	int tmp = 0;

	cin >> num;

	arr[0] = 1;
	for (int i = 1; i < MAX; i++) {
		tmp += 4;
		add += tmp;
		arr[i] = arr[i - 1] + add;
	}

	for (int i = 0; i < MAX; i++) {
		if (num < arr[i]) {
			cout << i << endl;
			break;
		}
		else if (num == arr[i]) {
			cout << i + 1 << endl;
			break;
		}
	}
	
	return 0;
}