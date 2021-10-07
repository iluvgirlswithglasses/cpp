#include <iostream>
#include <vector>
using namespace std;

const int K = 2e6+4;
int n, k;

int timer = 0;
long long calc() {
	cin >> k;
	int c, v;
	vector<int> f(4, 0);	// value dp
	vector<int> g(4, 0);	// count dp
	//
	while (k--) {
		cin >> c >> v;
		for (int i = 3; i >= 0; i--) {
			int pre = i - c;
			if (pre < 0) break;
			//
			if (f[pre] + v > f[i]) {
				f[i] = f[pre] + v;
				g[i] = g[pre] + 1;
			}
		}
	}
	//
	return f[3];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long res = 0;
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		res += calc();
	}
	cout << res << endl;
	return 0;
}
