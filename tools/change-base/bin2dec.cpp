#include <iostream>
#include <string>
using namespace std;

#define u64 unsigned long long

u64 calc(string &s) {
	u64 res = 0;
	for (int i = s.length()-1, p = 0; i >= 0; i--, p++) {
		res += (s[i]-'0') << p;
	}
	return res;
}

int main() {
	while (true) {
		string s; cin >> s;
		cout << calc(s) << "\n";
	}
}
