
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 14 16:38:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define ll long long

int n, q;
ll  a[26], b[26];

bool only_a(ll *a) {
	for (int i = 1; i < 26; i++)
		if (a[i] > 0) return false;
	return true;
}

bool calc() {
	if (!only_a(b)) return true;
	if (only_a(a) && only_a(b))
		return a[0] < b[0];
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int q; cin >> q;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		a[0] = b[0] = 1;
		while (q--) {
			int t, k;
			string x;
			cin >> t >> k >> x;
			for (char c: x) {
				if (t == 1) a[c - 'a'] += k;
				if (t == 2) b[c - 'a'] += k;
			}
			if (calc())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
