#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n; string s;
bool typ[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
int cnt[26];

int calc() {
	memset(cnt, 0, sizeof(cnt));
	for (int _i = 0; _i < n; _i++) {
		int i = s.at(_i) - 'A';
		//
		for (int j = 0; j < 26; j++) if (i != j) {
			if (typ[i] != typ[j]) {
				cnt[j]++;
			} else {
				cnt[j] += 2;
			}
		}
	}
	return *min_element(cnt, cnt+26);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s; n = s.length();
		cout << calc() << "\n";
	}
	return 0;
}
