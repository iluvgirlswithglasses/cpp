
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct  4 17:37:48 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// the applications of eratos algorithm

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second
const int I = 1e7+7;

struct Eratos {
	int  n, cnt;
	ll   p[I];	// p[i] == the i-th prime, 0-indexed
	bool e[I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		for (ll i = 2; i <= n; i++) if (!e[i]) {
			p[cnt++] = i;
			for (ll j = i*i; j <= n; j+=i) e[i] = true;
		}
	}

	/**
	 * factorizing functions
	 * */
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

	map<ll, int> fact_map(ll x) {
		map<ll, int> res;
		for (ll _i = 0, i = p[0]; i*i <= x; i = p[++_i]) {
			while (x % i == 0) {
				res[i]++;
				x /= i;
			}
		}
		if (x > 1) res[x]++;
		return res;
	}

	/**
	 * getting divisors functions
	 * */
	vector<ll> get_divisors(ll x) {
		int len = 1;
		vector<ll> res = {1};
		//
		for (ll _i = 0, i = p[0]; i*i <= x; i = p[++_i]) if (x % i == 0) {
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
	// write your test here
	int x; cin >> x;
	vector<ll> v = er.get_divisors(x);
	sort(v.begin(), v.end());
	for (int i: v)
		cout << i << " ";
	cout << "\n";
	return 0;
}
