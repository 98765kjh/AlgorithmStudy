#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX 1000001

bool arr[MAX];
int mem[MAX];
vector<int> prime;

int check(int a)
{
	if (mem[a] == 1 || a == 1)
		return 1;
	else if (mem[a] == -1)
		return -1;
	else if (mem[a] == 2)
		return -1;
	int tmp1 = a;
	int tmp2;
	int sum = 0;
	while (tmp1 != 0) {
		tmp2 = tmp1 % 10;
		tmp1 /= 10;
		sum += tmp2*tmp2;
	}
	mem[a] = 2;
	mem[a] = check(sum);
}

int main()
{
	ios::sync_with_stdio(false);
	
	int N;

	cin >> N;

	prime.push_back(2);
	for (int i = 2; i <= N; i+=2)
		arr[i] = true;
	for (int i = 3; i <=N; ++i) {
		if (!arr[i]) {
			prime.push_back(i);
			for (int j = i+i; j <= N; j += i)
				arr[j] = true;
		}
	}

	for (unsigned int i = 0; i < prime.size(); ++i) {
		if (prime[i] > N)	break;
		if (check(prime[i]) == 1)
			cout << prime[i] << endl;
	}

	return 0;
}