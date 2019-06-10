#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ENABLE -999999

string numstr;

int main()
{
	cin >> numstr;

	vector<int> num;
	vector<char> op;

	int pos = 0;
	for (int i = 0; i < numstr.length(); i++)
	{
		switch (numstr[i])
		{
		case '+':
		case '-':
			num.push_back( atoi(numstr.substr(pos, i-pos).c_str()) );
			op.push_back( numstr[i] );
			pos = i + 1;
		}

		if (i + 1 == numstr.length())	// last num
			num.push_back( atoi(numstr.substr(pos, (i+1) - pos).c_str()) );
	}

	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '+') {
			num[i + 1] = num[i] + num[i + 1];
			num[i] = ENABLE;
		}
	}

	int result = num[0];
	if (result == ENABLE)
	{
		for (int i = 1; i < num.size(); i++)
		{
			if (num[i] != ENABLE) {
				result = num[i];
				break;
			}
		}
	}

	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '-') {
			int pos = i+1;
			while (num[pos] == ENABLE) {
				pos++;
			}
			result = result - num[pos];

		}
	}

	cout << result;

	return 0;
}