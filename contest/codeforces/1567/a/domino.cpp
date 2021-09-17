#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n; string s;
unordered_map<char, char> dct;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	dct['L'] = 'L';
	dct['R'] = 'R';
	dct['U'] = 'D';
	dct['D'] = 'U';
	int t; cin >> t;
	while (t--) {
		cin >> n; cin >> s;
		for (int i = 0; i < n; i++) {
			cout << dct[s.at(i)];
		} cout << "\n";
	}
	return 0;
}
