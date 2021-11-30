
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 14:09:38 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define ll long long
#define st first
#define nd second

const int N = 1e3+7, S2A = 1e5+7, S4A = 320;

/**
 * eratos
 * */
// e[i] == 0 --> i is prime
bool e[S2A];
int  pcnt;
ll   p[S2A];

void eratos() {
	e[0] = 1;
	e[1] = 1;
	for (int i = 2; i < S2A; i++) if (e[i] == 0) {
		p[pcnt++] = i;
		if (i < S4A) for (int j = i*i; j < S2A; j+=i) {
			e[j] = 1;
		}
	}
}

/**
 * drivers
 * */
int n, k;
ll  a;
map<ll, int> dp;

vector<ll> get_divisors(ll a) {
	int len = 1;
	vector<ll> u = {1};
	//
	for (ll _i = 0, i = p[_i]; i * i <= a; i = p[++_i]) 
	if (a % i == 0) {
		ll t = i;
		while (a % i == 0) {
			for (int j = 0; j < len; j++)
				u.push_back(u[j] * t);
			a /= i;
			t *= i;
		}
		len = u.size();
	}
	if (a > 1) {
		for (int j = 0; j < len; j++)
			u.push_back(u[j] * a);
	}
	//
	return u;
}

int get() {
	for (map<ll, int>::iterator p = --dp.end(); ; --p) {
		if (p->nd >= k) return p->st;
	}
	// this never gonna happens
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	eratos();
	//
	cin >> n >> k;
	while (n--) {
		cin >> a;
		vector<ll> u = get_divisors(a);
		for (ll i: u) dp[i]++;
	}
	//
	cout << get() << "\n";
	return 0;
}
