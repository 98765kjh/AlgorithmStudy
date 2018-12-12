//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<vector>
//#include<string>
//#include<cstring>
//#include<iostream>
//
//using namespace std;
//int main() {
//	string input, temp;
//	cin >> input;
//	int cnt = 0;
//	for (int i = 0; i < input.size(); i++) {
//		temp = input.substr(i, input.size() - i);
//		bool flag = true;
//		for (int j = 0; j < temp.size() / 2; j++) {
//			if (temp[j] != temp[temp.size() - 1 - j]) {
//				flag = false;
//				break;
//			}
//		}
//		if (flag) {
//			cnt = i;
//			break;
//		}
//	}
//	printf("%d\n", temp.size() + cnt * 2);
//}