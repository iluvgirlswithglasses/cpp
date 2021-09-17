#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	int test;
	cin >> test;
	getline(cin, s);
	while (test--) {
		getline(cin, s);
		int demd = 0;
		int demc = 0;
		int so1 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1'){
                so1 = 1;
                break;
			}
			demd++;
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '1')break;
			demc++;
		}
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') res++;
		}
		res = res - demd - demc;
		if (res < 0) res = 0;
		if (so1 == 0) cout << -1 << endl; else
		cout << res << endl;
	}
}
