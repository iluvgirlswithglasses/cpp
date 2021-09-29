#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 1e5+7;
int n, k; ll a[N];

ll sigma(ll n, ll u) {
	return n*((u<<1) - (n-1))>>1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n, [](int i, int j){
		return i > j;
	});
	a[n++] = 0;
	//
	ll res = 0;
	for (int i = 1; i < n; i++) {
		ll l = a[i-1] - a[i];
		ll c_k = l*i;
		ll c_a = (sigma(l, a[i-1])) * i;
		//
		if (k < c_k) {
			l = k/i;
			res += sigma(l, a[i-1])*i + (a[i-1] - l)*(k%i);
			break;
		}
		res += c_a;
		k -= c_k;
		if (k == 0) break;
	}
	cout << res << "\n";
	return 0;
}
