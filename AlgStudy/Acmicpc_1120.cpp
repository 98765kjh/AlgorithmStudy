#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B;

	cin >> A >> B;

	int N = B.length() - A.length() + 1;

	int differ_min = 9999;
	for (int i = 0; i < N; i++)
	{
		int differ = 0;
		for (int pos = 0; pos < A.length(); pos++)
		{
			if (A[pos] != B[pos + i])
				differ = differ + 1;
		}
		if (differ_min > differ)
			differ_min = differ;
	}

	cout << differ_min;

	return 0;
}