#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v;
		if (n >= 4) {
			for (int i = 1; i < n - n%4; i++) {
				v.push_back(i);
			}
			if (n % 4 == 3) {
				v.push_back(n-3);
				v.push_back(n-2);
				v.push_back(n-1);
			} else {
				v.push_back(n);
			}
		} else {
			// n < 4
			if (n % 4 == 3) {
				v.push_back(n-2);
				v.push_back(n-1);
			} else {
				v.push_back(n);
			}
		}
		// prnt
		cout << v.size() << "\n";
		for (int i: v) {
			cout << i << " ";
		} cout << "\n";
	}
	return 0;
}
