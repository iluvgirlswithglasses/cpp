/*
nước đọng, phiên bản được đem đi thi

start:	1:45:59.06
end:	2:11:49.25

cái vụ số âm lấy mất gần 20 phút...
*/

#include <iostream>
using namespace std;

#define ll long long
const int N = 1e5+7;
ll n, m, a[N], l[N], r[N];

ll calc(ll lim) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		//
		res += max(
			(ll)0, min(l[i], r[i]) - max(lim, a[i])
		);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) l[i] = max(a[i], l[i-1]);
	for (int i = n; i >= 1; i--) r[i] = max(a[i], r[i+1]);
	//
	ll lo = 0, hi = l[n];
	while (lo < hi) {
		ll mi = (lo + hi + 1) >> 1;
		if (calc(mi) >= m) {
			lo = mi;
		} else {
			hi = mi - 1;
		}
	}
	if (calc(lo) >= m) {
		cout << lo << "\n";
	} else {
		cout << -1 << "\n";
	}
	return 0;
}