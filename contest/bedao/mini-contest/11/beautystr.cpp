
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Sep  3 23:19:53 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define ll long long
#define pi pair<const ll, int>
#define st first
#define nd second
const int N = 1e5+7, A = 36;
int n, s[N];

// read './beautystr-brute.cpp' to understand what is going on

// x[i]: xor of s[1:i]
// --> x[r] ^ x[l-1] == xor of s[l:r]
ll x[N];
map<ll, int> m;

void inp() {
	char t[N];
	cin >> n >> (t+1);
	for (int i = 1; i <= n; i++) {
		if ('0' <= t[i] && t[i] <= '9') s[i] = t[i] - '0';		// num:  [0:10)
		if ('a' <= t[i] && t[i] <= 'z') s[i] = t[i] - 'a' + 10;	// char: [10:36)
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	inp();
	//
	ll res = 0;
	m[0] = 1;
	for (int r = 1; r <= n; r++) {
		int c = s[r];
		x[r] = x[r-1] ^ (1ll<<c);
		//
		res += m[x[r]];	// x[r] ^ x[r] == 0
		for (int i = 0; i < A; i++)
			res += m[x[r]^(1ll<<i)];	// find `x[l]` which `x[r] ^ x[l] == (1ll<<i)`
		m[x[r]]++;
	}
	cout << res << "\n";
	return 0;
}
