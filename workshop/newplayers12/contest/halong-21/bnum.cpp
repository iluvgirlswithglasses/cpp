
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 29 13:43:15 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const ll N = 1e6+7;
ll n;

bool er[N];	// er[i] == true --> er[i] isn't prime

bool is_prime(int i) {
	return !er[i];
}

void eratosthenes() {
	er[0] = true;
	er[1] = true;
	for (ll i = 2; i < N; i++) {
		if (!er[i]) {
			for (ll j = i * i; j < N; j+=i) {
				er[j] = true;
			}
		}
	}
}

/**
 * 
 * */

vector<ll> r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	eratosthenes();
	//
	cin >> n;
	for (ll i = 2; i*i <= n; i++) if (is_prime(i)) {
		if (n % i == 0) r.push_back(i);
		while (n % i == 0) n /= i;
	}
	if (n > 1) r.push_back(n);
	//
	ll res = 1;
	for (ll &i: r) res *= i;
	cout << res << "\n";
	return 0;
}

