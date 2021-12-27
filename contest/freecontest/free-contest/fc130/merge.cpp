
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 27 11:40:27 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
tóm gọn:
vị trí của n trong p phải to hơn vị trí của n-1 trong p

gọi s = n + m + k
giả sử chọn tập n trước:
-->	có sCn cách chọn n
-->	còn lại (s-n)Cm cách chọn m & nhường các index còn lại cho k
*/

#define ll long long
const ll R = 1e9+7;
ll n, m, k, s;

// calculate ((a**b) % R) real quick
ll fast_exponential(ll a, ll b) {
	if (b == 0) return 1l;
	if (b == 1) return a;
	if (b & 1) {
		// (b^1)>>1 == (b-1)/2
		ll tmp = fast_exponential(a, (b^1)>>1);
		return ( ((tmp * tmp) % R) * a ) % R;
	}
	// if b is even
	ll tmp = fast_exponential(a, b>>1);
	return (tmp * tmp) % R;
}

ll nCk(ll n, ll k) {
	ll a = 1, b = 1;
	// n(n-1)...(n-k+1)
	for (int i = n; i >= n - k + 1; i--)
		a = (a * i) % R;
	// k!
	for (int i = 2; i <= k; i++) 
		b = (b * i) % R;
	// Fermat little theorem
	// (a/b)%R = (a * b^(R-2)) % R
	// đk: R là số nguyên tố
	ll res = (a * fast_exponential(b, R-2)) % R;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	s = n + m + k;
	ll res = (nCk(s, n) * nCk(s-n, m)) % R;
	cout << res << "\n";
	return 0;
}
