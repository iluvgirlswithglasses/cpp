
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Sep  3 19:39:42 2022
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

// this is not yet completed

#define ll long long
#define pi pair<const ll, int>
#define st first
#define nd second
const int N = 1e5+7, A = 36;
int n, s[N], cnt[A][N];		// cnt[c][i]: number of `c` in range [1:i]

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
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c < A; c++) cnt[c][i] = cnt[c][i-1];
		cnt[s[i]][i]++;
	}
	//
	ll res = 0;
	for (int r = 1; r <= n; r++) {
		int c = s[r];
		// p.st[c] == 0 if number of `c` in [1:r] is even
		map<ll, int> t;
		for (pi &p: m)
			if (p.nd) t[p.st ^ (1ll<<c)] = p.nd;
		t[1ll<<c]++;
		//
		res += t[0];
		for (int i = 0; i < A; i++)
			res += t[1ll<<i];
		m = t;
	}
	cout << res << "\n";
	return 0;
}
