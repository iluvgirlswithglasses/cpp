
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
#include <vector>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int I = 1e9+7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
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
			return !e[x];
		for (int _i = 0, i = p[0]; i * i <= x; i = p[++_i])
			if (x % i == 0) return false;
		return true;
	}
} er;

// document will come later
// https://github.com/iluvgirlswithglasses/cpp/contest/freecontest/free-contest/fc101/sumfrac.pdf

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	er.init((int) 1e7);
	int tt; cin >> tt;
	while (tt--) {	
		ll n; cin >> n;
		ll f, g;
		for (int i = n; i >= 2; i--) if (er.is_prime(i)) {
			f = i;
			break;
		}
		for (int i = n+1; i <= I; i++) if (er.is_prime(i)) {
			g = i;
			break;
		}
		
		ll y = f * g * 2;	// lcm(2*f, f*g)
		ll x = (f - 2)*g + (n - f + 1)*2;
		//     ^ before f  ^ after f
		
		ll k = gcd(y, x);
		x /= k;
		y /= k;
		cout << x << "/" << y << "\n";
	}
	return 0;
}
