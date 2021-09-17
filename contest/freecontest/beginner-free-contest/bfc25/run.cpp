#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n, x[N], y[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	sort(x, x+n); sort(y, y+n);
	int u = x[n/2], v = y[n/2];
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(x[i] - u) + abs(y[i] - v);
	}
	cout << res << "\n";
	return 0;
}
