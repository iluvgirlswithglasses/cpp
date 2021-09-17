/*
nước đọng, phiên bản được đem đi thi

start:	1:45:59.06
end:	
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
			0, min(l[i], r[i]) - max(lim, a[i])
		);
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) l[i] = max(a[i], l[i-1]);
	for (int i = n; i >= 1; i--) r[i] = max(a[i], r[i+1]);
	//
	while (true) {
		ll x; cin >> x;
		cout << calc(x) << "\n";
	}
	return 0;
}