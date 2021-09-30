#include <iostream>
using namespace std;

#define ll long long

const ll N = 102, K = 1e5+7, R = 1e9+7;
ll n, a, k, p[N][K];
// p[i][j] == số cách chia j viên kẹo cho i đứa trẻ đầu tiên

ll get(int i, int j) {
	if (j < 0) return 0;
	return p[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (ll i = 0; i <= n; i++) p[i][0] = 1;
	for (ll i = 0; i <= k; i++) p[0][i] = 1;
	//
	for (ll i = 1; i <= n; i++) {
		cin >> a;
		for (ll j = 1; j <= k; j++) {
			ll &cr = p[i][j];
			cr = get(i, j-1) + get(i-1, j) - get(i-1, j-a-1);
			cr = (cr + R) % R;
		}
	}
	cout << get(n, k) - get(n, k-1) << "\n";
	return 0;
}
