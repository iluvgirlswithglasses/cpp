
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 14:54:43 2022
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

// x != 0
inline int dig(int x) {
	int cnt = 1;
	while (x/=10) cnt++;
	return cnt;
}

const int N = 2e5+7;
int n;
// a[i]: count of `i` in `a`
map<int, int> a, b;

void excludeSame() {
	// already equals
	// --> no need to interfere
	for (map<int, int>::iterator i = a.begin(), nxt = i; i != a.end(); i = nxt) {
		nxt++;
		int k = i->st, v = i->nd;
		if (v > 0 && b[k] > 0) {
			int reduce = min(v, b[k]);
			a[k] -= reduce;
			b[k] -= reduce;
			if (b[k] == 0) b.erase(k);
			if (a[k] == 0) a.erase(i);
		}
	}
}

void change(map<int, int> &m, int lim, int &res) {
	for (map<int, int>::iterator i = m.begin(), nxt = i; i != m.end(); i = nxt) {
		nxt++;
		if (i->st >= lim) {
			res += i->nd;
			m[dig(i->st)] += i->nd;
			m.erase(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int res = 0;
		cin >> n;
		for (int i = 0, x; i < n; i++) {
			cin >> x; a[x]++;
		}
		for (int i = 0, x; i < n; i++) {
			cin >> x; b[x]++;
		}
		excludeSame();
		// turns every number to single digit
		change(a, 10, res);
		change(b, 10, res);
		excludeSame();
		// turns the rest to 1
		change(a, 2, res);
		change(b, 2, res);
		//
		cout << res << "\n";
	}
	return 0;
}
