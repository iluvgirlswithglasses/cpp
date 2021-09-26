#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define u64 unsigned long long

u64 val(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	if ('a' <= c && c <= 'f') return 10 + c - 'a';
	if ('A' <= c && c <= 'F') return 10 + c - 'A';
	return 0;
}

u64 calc(string &s) {
	u64 res = 0;
	for (int i = s.length()-1, p=0; i >= 0; i--, p++) {
		res += val(s[i]) * (u64) pow(16, p);
	}
	return res;
}

int main() {
	while (true) {
		string s; cin >> s;
		cout << calc(s) << "\n";
	}
}
