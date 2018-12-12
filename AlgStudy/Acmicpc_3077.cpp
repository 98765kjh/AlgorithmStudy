#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	int N;
	string str;
	vector<string> VS;
	vector<pair<string, int> > VSI;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		VS.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		cin >> str;
		VSI.push_back({ str,0 });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (VSI[i].first == VS[j]) {
				VSI[i].second = j;
				break;
			}
		}
	}

	int score = 0;
	int sum = N*(N - 1) / 2;

	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (VSI[i].second < VSI[j].second)
				score++;
		}
	}
	cout << score << "/" << sum << endl;

	return 0;
}