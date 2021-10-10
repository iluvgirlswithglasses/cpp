#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool tobool(char c) {
	return c == 'B';
}

char tochar(bool c) {
	if (c) return 'B';
	return 'R';
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; string s; cin >> s;
		//
		vector<char> v(n);
		for (int i = 0; i < n; i++) v[i] = s.at(i);
		int i = 0;
		bool state = false;
		// before
		for (; i < s.length(); i++) {
			char cr = s.at(i);
			if (cr != '?') {
				state = tobool(cr);
				for (int j = i-1; j>=0; j--) {
					state ^= 1;
					v[j] = tochar(state);
				}
				break;
			}
		}
		if (i == s.length()) i = 0;
		// after
		for (; i < s.length(); i++) {
			char cr = s.at(i);
			if (cr == '?') {
				state ^= 1;
				cr = tochar(state);
			} else {
				state = tobool(cr);
			}
			v[i] = cr;
		}
		//
		for (char c: v) cout << c; cout << endl;
	}
	return 0;
}
