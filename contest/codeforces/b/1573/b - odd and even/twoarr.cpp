#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, a[N], b[N];

int calc() {
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < t+1; i++) {
			if (a[i] < b[t - i]) {
				return t;
			}
		}
	}
	// never gonna happen
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		cout << calc() << "\n";
	}
	return 0;
}
