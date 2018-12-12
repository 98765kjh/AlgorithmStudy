#include <iostream>
#include <string>
using namespace std;

long long excep[10] = { 1, 10, 102, 1023, 10234, 
						102345, 1023456, 10234567, 
						102345678, 1023456789 };
bool check[10];

int main()
{
	string N;
	string result = "";
	int K;

	cin >> N >> K;

	int s_size = N.length();

	// 일반
	if (s_size >= K) {
		for (int i = 0; i < 10; i++)	check[i] = false;
		int cnt = 0;
		int pos = -1;
		int num;
		for (int i = 0; i < s_size; i++) {
			num = N[i] - '0';
			if (!check[num]) {
				check[num] = true;
				result += num + '0';
				cnt++;
			}
			if (cnt == K) {
				pos = i;
				break;
			}
		}

		// 최소값 찾기
		int min = 9;
		for (int i = 0; i < 10; i++) {
			if (check[i]) {
				min = i;
				break;
			}
		}

		// 숫자 N의 서로다른 자연수 개수가 K개 미만일 경우
		if (cnt < K) {

		}

		
		result[pos]++;
		for (int i = cnt; i < s_size; i++) {
			result += min + '0';
		}

		cout << result << endl;
	}
	// 예외
	else {
		cout << excep[K - 1] << endl;
	}

	return 0;
}
