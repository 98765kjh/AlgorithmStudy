#include <iostream>
using namespace std;

int main()
{
	int M;
	int left[1000];
	int right[1000];
	int result;

	cin >> M;
	for (int i = 0; i < M; i++)	
		cin >> left[i];
	for (int i = 0; i < M; i++) 
		cin >> right[i];

	result = 0;
	int i = M - 1;
	int j = M - 1;

	while (1) {
		if (i < 0 || j < 0)
			break;


		if (right[j] < left[i]) {
			result += right[j];
			j--;
		}
		else {
			i--;
		}
	}
	
	cout << result << endl;

	return 0;
}

