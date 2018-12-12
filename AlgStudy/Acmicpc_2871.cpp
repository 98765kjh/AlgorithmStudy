#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	int N;
	string hee, sang;
	string str;
	bool used[100000];
	vector< int > word[26];

	cin >> N;
	// 초기화
	for (int i = 0; i < N; i++)
		used[i] = false;
	//입력
	cin >> str;
	for (int i = 0; i < N; i++)
		word[str[i] - 'a'].push_back(i);
	
	// 상원 -> 희원 -> ...
	int num = 1;
	int pos;
	for (int i = 0; i < N; i = i + 2) {
		while (1) {
			if (!used[N - num]) {
				sang += str[N - num];

				used[N - num] = true;
				word[str[N - num] - 'a'].pop_back();
				break;
			}
			num++;
		}

		for (int i = 0; i < 26; i++) {
			if (word[i].size()) {
				pos = word[i].at(word[i].size() - 1);

				used[pos] = true;
				hee += str[pos];
				word[i].pop_back();
				break;
			}
		}

	}

	if (hee < sang) 
		cout << "DA" << endl;
	else 
		cout << "NE" << endl;

	cout << hee << endl;

	return 0;
}