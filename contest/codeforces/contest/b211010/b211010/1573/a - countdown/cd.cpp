#include <iostream>
#include <string>
using namespace std;

int n; string s;

int calc() {
	int r = 0;
	for (int i = 0; i < n-1; i++) {
		char c = s.at(i);
		int v = c - '0';
		if (v > 0)
			r += 1 + v;
	}
	return r + (s.at(n-1) - '0');
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		cout << calc() << "\n";
	}
	return 0;
}
