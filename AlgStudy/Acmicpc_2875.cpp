#include <iostream>
using namespace std;

int main()
{
	int girl, boy, internship;

	cin >> girl >> boy >> internship;

	int team = 0;
	int tmp = 0;
	if (2 * boy <= girl) {
		team = boy;
		tmp = girl - 2 * team;
	}
	else {
		team = girl / 2;
		tmp = (boy - team) + (girl - 2 * team);
	}

	internship = internship - tmp;
	if (internship > 0) {
		team = team - (internship + 2) / 3;
	}


	cout << team;

	return 0;
}