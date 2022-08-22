#include <iostream>
using namespace std;

int n, l, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		int v; cin >> v;
		l = min(l, v); r = max(r, v);
	}
	int res = -2*l + 2*r;
	cout << res << "\n";
	return 0;
}
