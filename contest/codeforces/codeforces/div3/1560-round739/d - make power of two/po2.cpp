#include <iostream>
#include <string>
using namespace std;

#define u64 unsigned long long
string n, po2[64];

int compare(string &s) {
	int m = 0;
	for (int i = 0; m < s.length() && i < n.length(); i++) {
		if (n[i] == s[m]) m++;
	}
	return m;
}

int calc() {
	int res = 1e9+7;
	int len = n.length() << 1;
	//
	int i = 0; string s = po2[0];
	for (; i < 64 && s.length() <= len; s = po2[++i]) {
		int lmatch = compare(s),
			erase  = n.length() - lmatch,
			add    = s.length() - lmatch;
		res = min(res, erase + add);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (u64 i = 0, _tmp=1; i < 64; i++) 
		po2[i] = to_string(_tmp<<i);
	//
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cout << calc() << "\n";
	}
	return 0;
}
