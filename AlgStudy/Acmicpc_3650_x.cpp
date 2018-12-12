#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1, str2;
int k, len;
vector<string> org, enc;
vector<int> vi;

void part(int k, int parts)
{
	for (int i = 0; i < parts; i++) {
		org.push_back(str1.substr(i*k, k));
		enc.push_back(str2.substr(i*k, k));
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	while (cin >> k)
	{
		org.clear();
		enc.clear();

		cin >> str1 >> str2;
		len = str1.size();

		part(k, len / k);

		for (int i = 0; i < len / k; i++) {

		}
	}

	return 0;
}