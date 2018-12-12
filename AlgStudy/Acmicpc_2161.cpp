#include <iostream>
#include <list>
using namespace std;

list<int> lst;

int main()
{
	int N;
	int num;
	cin >> N;
	for (int i = 0; i < N; i++)
		lst.push_back(i + 1);

	while(1) {
		num = lst.front();
		lst.pop_front();

		cout << num << " ";
		
		if (lst.empty())
			break;
		num = lst.front();
		lst.pop_front();
		lst.push_back(num);
	}
	cout << endl;

	return 0;
}