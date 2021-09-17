#include <iostream>
using namespace std;

int n, m, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		res = max(res, m - v);
		m = max(m, v);
	}
	if (res > 0) {
		cout << res << endl;
	} else {
		cout << "Lo nang roi!\n";
	}
	return 0;
}
