/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 29 14:14:22 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n, a[N], last[26];

// f[c][i] == how many char `c` in node `i`
int f[26][N<<1];

int query(int c, int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[c][l++];
		if (r&1) res += f[c][--r];
	}
	return res;
}

void read() {
	string s; cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - 'a';
		f[a[i]][n+i] = 1;
	}
	for (int c = 0; c < 26; c++)
	for (int i = n-1; i >= 1; i--) {
		f[c][i] = f[c][i<<1] + f[c][i<<1|1];
	}
}

ll calc() {
	ll res = 0;
	last[a[0]] = 1;
	for (int r = 1; r < n; r++) {
		int l = last[a[r]];
		//
		for (int c = 0; c < 26; c++) {
			// if there > 1 `c` in this seg
			// only 1 `c` can make s[c:r]
			res += min(query(c, l, r), 1);
		}
		//
		last[a[r]] = r+1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	read();
	cout << calc() << "\n";
	return 0;
}

