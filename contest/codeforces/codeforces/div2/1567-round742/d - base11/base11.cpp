#include <iostream>
#include <vector>
using namespace std;

int s, n;

void calc(vector<int> &f) {
	int i = 0;
	for (int e = 1e9; e > 0; e /= 10) {
		while (s >= e && s-e >= n-(i+1)) {	// n-(i+1): unfilled count
			f[i++] += e;
			s -= e;
			if (i == n) {
				f[n-1] += s;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s >> n;
		if (n == 1)
			cout << s << "\n";
		else {
			vector<int> f(n, 0);
			calc(f);
			//
			for (int &i: f) cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}
