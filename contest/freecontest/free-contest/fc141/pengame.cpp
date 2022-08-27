
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 27 19:37:30 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

const int R = 1e9+7, I = 1e9+7, K = 1e6+7;
int n, k, l, r, w;

ll fast_exponential(ll a, ll b) {
	if (b == 0) return 1ll;
	if (b == 1) return a;
	if (b & 1) {
		ll c = fast_exponential(a, (b^1)>>1);
		return (((c * c) % R) * a) % R;
	}
	ll c = fast_exponential(a, b>>1);
	return (c * c) % R;
}

int nCk(int n, int k) {
	// returns (n!) / (k!(n-k)!)
	ll a = 1, b = 1;
	for (int i = n; i >= n-k+1; i--)
		a = (a * i) % R;
	for (int i = k; i > 1; i--)
		b = (b * i) % R;
	// fermat
	return (a * fast_exponential(b, R-2)) % R;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> l >> r;
	w = r - l + 1;
	if (k == 1) {
		cout << w << "\n";
	} else if (k == 2) {
		cout << nCk(w, 2) << "\n";
	} else {
		// cấp số cộng `d` chiếm `d*(k-1) + 1` chỗ trong [l:r]
		ll res = 0;
		for (int d = 1, s = d*(k-1) + 1; s <= w; s = (++d)*(k-1) + 1) {
			res += w - s + 1;
			if (res > R) res -= R;
		}
		cout << res << "\n";
	}
	return 0;
}
