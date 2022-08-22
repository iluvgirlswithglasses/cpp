
// chứng minh (l[i] = a[i] + b[i]) trong nháp số 1
// ngay sau nháp bài sum-of-max-weight

#include <iostream>
using namespace std;

const int N = 1e4+4;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		int best = 0;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			best = max(best, a + b);
		}
		cout << best << "\n";
	}
	return 0;
}
