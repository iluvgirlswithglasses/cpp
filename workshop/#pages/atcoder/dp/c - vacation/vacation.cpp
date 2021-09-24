#include <iostream>
#include <algorithm>
using namespace std;

int n, f[3], g[3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0, a, b, c; i < n; i++) {
		cin >> a >> b >> c;
		f[0] = max(g[1], g[2]) + a;
		f[1] = max(g[0], g[2]) + b;
		f[2] = max(g[0], g[1]) + c;
		swap(f, g);
	}
	cout << *max_element(g, g+3) << "\n";
	return 0;
}
