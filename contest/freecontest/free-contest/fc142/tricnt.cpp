
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 20 13:29:47 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second
const int R = 1e9+7, I = 1e5+7;
int nCk[I][4];

int add(int a, int b) {
	int c = a + b;
	if (c >= R) return c - R;
	return c;
}

int mul(int a, int b) {
	return (ll) a * b % R;
}

const int N = 1007;
int n, len[N];
map<int, int> s;	// s[i]: số que dài `i`
map<int, int> t;	// t[i]: số que có độ dài `<= i`

void init() {
	nCk[0][0] = 1;
	for (int i = 1; i < I; i++) {
		nCk[i][0] = 1;
		for (int j = 1; j <= 3; j++)
			nCk[i][j] = add(nCk[i-1][j-1], nCk[i-1][j]);
	}
	//
	sort(len, len+n);
	t[0] = 0;
	for (int i = 1; i < n; i++) 
		t[len[i]] += t[len[i-1]];
}

int calc() {
	int res = 0;
	// 3 giống
	for (pi &p: s) res = add(res, nCk[p.nd][3]);
	// 2 giống 1 khác
	for (int j = 0; j < n; j++) 
	for (int k = 0; k < n; k++) if (k != j && len[k] < len[j] + len[j]) {
		int ab = nCk[ s[len[j]] ][2];
		res = add(res, mul(ab, s[len[k]]));
	}
	// 3 khác
	for (int i = 0; i < n; i++)
	for (int j = i+1; j < n; j++) {
		map<int, int>::iterator l = t.lower_bound(len[j]),
								r = --t.lower_bound(len[j] + len[i]);
		res = add(
			res, 
			mul( s[len[i]], mul( s[len[j]], r->nd - l->nd) )
		);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		len[i] = a;
		s[a] = t[a] = b;
	}
	init();
	cout << calc() << "\n";
	return 0;
}
