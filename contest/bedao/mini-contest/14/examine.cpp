
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 12 13:42:14 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll R = 1e9+7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

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

	/**
	 * lấy các ước bé hơn sqr(x)
	 * */
	vector<ll> get_divisors(ll x) {
		int len = 1;
		vector<ll> v = {1};
		//
		for (ll _i = 0, i = p[0]; _i < cnt && i*i <= x; i = p[++_i]) if (x % i == 0) {
			ll t = i;
			while (x % i == 0) {
				for (int j = 0; j < len; j++)
					v.push_back(v[j] * t);
				x /= i;
				t *= i;
			}
			len = v.size();
		}
		if (x > 1) {
			for (int j = 0; j < len; j++)
				v.push_back(v[j] * x);
		}
		//
		return v;
	}
} er;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	er.init((int) 1e7);
	int tt; cin >> tt;
	while (tt--) {
		ll n, res = 0;
		cin >> n;
		vector<ll> v = er.get_divisors(n);
		for (ll a: v) {
			ll b = n / a;
			if (b <= a)
				continue;
			if (gcd(b, a) == 1)
				res += a + b;
		}
		//
		res %= R;
		n %= R;
		cout << (res*n) % R << "\n";
	}
	return 0;
}
