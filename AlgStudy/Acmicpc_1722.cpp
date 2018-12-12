#include <iostream>
#include <vector>
using namespace std;

vector<long long> vt;
int perm[21];

void Construct(int p, long long k, vector<bool> &used)
{
	if (p == 1){
		for (int i = 1; i < (int)used.size(); i++){
			if (!used[i]) {
				cout << i;
				break;
			}
		}
	}
	else {
		for (int i = 1; i < (int)used.size(); i++){
			if (!used[i]) {
				if (k <= vt[p - 1]) {
					used[i] = true;
					cout << i << " ";
					Construct(p - 1, k, used);
					return;
				}
				k -= vt[p - 1];
			}
		}
	}
}

long long kth(int p, vector<bool> &used)
{
	if (p == 1)	return 1;
	else {
		long long k=0;
		for (int i = 1; i < (int)used.size(); i++) {
			if (!used[i]) {
				if (i == perm[p]) {
					used[i] = true;
					return kth(p - 1, used) + k;
				}
				k += vt[p - 1];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int N, p;
	long long k;

	vt.resize(21);
	vt[1] = 1;
	for (int i = 2; i < 21; i++)
		vt[i] = vt[i - 1] * i;

	cin >> N >> p;
	if (p == 1) {
		cin >> k;
		vector<bool> used(N + 1, false);
		Construct(N, k, used);
		
	}
	else {
		vector<bool> used(N + 1, false);
		for (int i = N; i>0; i--) {
			cin >> perm[i];
		}
		cout<<kth(N, used);
	}
	cout << endl;

	return 0;
}