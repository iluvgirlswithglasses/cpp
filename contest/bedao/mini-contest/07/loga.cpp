
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 20:40:52 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define st first
#define nd second

/**
 * eratos
 **/
const ll N = 1e6+7;
ll n;

bool er[N];	// er[i] == true --> er[i] isn't prime
vector<ll> primes;

void eratos() {
	er[0] = true;
	er[1] = true;
	for (ll i = 2; i < N; i++) {
		if (!er[i]) {
			primes.push_back(i);
			for (ll j = i * i; j < N; j+=i) {
				er[j] = true;
			}
		}
	}
}

/**
 *
 **/
ll a, b, x;

ll getlog(ll a, ll b) {
	// with a = b^x
	// return x
	ll o_a = a, o_b = b, p = 0;
	while (a > 1) {
		a /= b;
		p++;
	}
	for (int i = 1; i < p; i++) {
		b *= o_b;
	}
	if (b == o_a) return p;
	return (ll) -1;
}

void prf(map<ll, ll> &f) {
	for (auto pi: f) {
		cout << pi.nd << " ";
	} cout << "\n";
	for (auto pi: f) {
		cout << pi.st << " ";
	} cout << "\n";
}

map<ll, ll> fact(ll n) {
	map<ll, ll> f;
	for (ll i = 0, p = primes[0]; p * p <= n; p = primes[++i]) {
		while (n % p == 0) {
			n /= p;
			f[p]++;
		}
	}
	if (n > 1) f[n] = 1;
	return f;
}

void calc() {
	cin >> a >> b >> x;
	if (a == 1) {
		cout << -1 << "\n";
	} else {
		ll p = getlog(b, a);
		if (p == -1) {
			cout << -1 << "\n";
		} else {
			ll res = p * x;
			map<ll, ll> f = fact(res);
			prf(f);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	eratos();
	//
	int t; cin >> t;
	while (t--) calc();
	return 0;
}

