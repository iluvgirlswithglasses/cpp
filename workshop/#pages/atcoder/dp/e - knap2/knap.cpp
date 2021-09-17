#include <iostream>
using namespace std;

#define ll long long

const int N = 102, V = 1002;
// mw: max-weight
// mv: max-value
int n, mv, w[N], v[N];
ll mw, dp[N][N*V];

// crw: current value
//   i: current item
ll calc(int crv, int i) {
	if (i == n) {
		if (crv == 0) return 0;
		else return 2e9;
	}
	if (dp[i][crv]) return dp[i][crv];
	//
	ll res = calc(crv, i+1);
	if (v[i] <= crv)
		res = min(res, w[i] + calc(crv - v[i], i+1));
	dp[i][crv] = res;
	return res;
}

int main() {
	cin >> n >> mw;
	//
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		mv += v[i];
	}
	for (int i = mv; i >= 0; i--)  {
		if (calc(i, 0) <= mw) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
