
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct  5 10:11:15 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// https://vi.wikipedia.org/wiki/H%C3%A0m_phi_Euler
// https://en.wikipedia.org/wiki/Euler%27s_totient_function

#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int I = 1e7+7;

struct Eratosthenes {

	int  n, cnt;
	int  p[I];	// p[i] == the i-th prime
	bool e[I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		p[0] = 2;	// in case of n == 1
		for (ll i = 2; i <= n; i++) if (!e[i]) {
			p[cnt++] = i;
			for (ll j = i*i; j <= n; j+=i) e[j] = true;
		}
	}

	vector<ll> fact(ll x) {
		vector<ll> res;
		for (ll _i = 0, i = p[0]; i*i <= x; i = p[++_i]) {
			if (x % i == 0) {
				res.push_back(i);
				while (x % i == 0) x /= i;
			}
		}
		if (x > 1) res.push_back(x);
		return res;
	}

} er;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	er.init(n);
	//
	vector<ll> f = er.fact(n);
	for (int i: f)
		n = n / i * (i-1);
	cout << n << "\n";
	return 0;
}
