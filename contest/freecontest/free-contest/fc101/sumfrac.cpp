
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 29 21:12:18 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

ll __gcd(ll a, ll b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

ll gcd(ll a, ll b) {
	return a > b ? __gcd(a, b) : __gcd(b, a);
}

ll lcm(vector<ll> &a) {
	ll x = a[0];
	for (int i = 1; i < n; i++) {
		x = (x * a[i]) / gcd(x, a[i])
	}
	return x;
}

// https://en.wikipedia.org/wiki/Prime_gap
// --> max prime gap for this pb's constraints is 288
// --> we can brute force

struct Eratos {

	static const int I = 1e7+7;

	int  n, cnt;
	ll   p[Eratos::I];	// p[i] == the i-th prime, 0-indexed
	bool e[Eratos::I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		for (ll i = 2; i <= n; i++) if (e[i] == 0) {
			p[cnt++] = i;
			for (ll j = i*i; j <= n; j+=i) e[j] = true;
		}
	}

	bool is_prime(ll x) {
		if (x <= n)
			return !e[i];
		for (int _i = 0, i = p[0]; i * i <= x; i = p[++_i])
			if (x % i == 0) return false;
		return true;
	}

	vector<ll> get_divisors(ll x) {
		int len = 1;
		vector<ll> res = {1};
		//
		for (ll _i = 0, i = p[0]; i * i <= x; i = p[++_i]) if (x % i == 0) {
			ll t = i;
			while (x % i == 0) {
				for (int j = 0; j < len; j++)
					res.push_back(res[j] * t);
				x /= i;
				t *= i;
			}
			len = res.size();
		}
		if (x > 1) {
			for (int j = 0; j < len; j++)
				res.push_back(res[j] * x);
		}
		//
		return res;
	}
} er;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	er.init((int) 1e7);
	int tt; cin >> tt;
	while (tt--) {	
		cin >> n;
		
	}
	return 0;
}
