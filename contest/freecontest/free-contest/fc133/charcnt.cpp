
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec  5 13:09:44 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 5e5+7;
int n, q;
char s[N];
unsigned short f[26][N<<1];

// get(i, l, r): trả về số ký tự `i` do cây `i` quản lý có trong đoạn [l:r)
int get(int i, int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[i][l++];
		if (r&1) res += f[i][--r];
	}
	return res;
}

void upd(int i, int p, int v) {
	for (p+=n; p > 0; p>>=1)
		f[i][p] += v;
}

int cnt(int l, int r) {
	int res = 0;
	for (int i = 0; i < 26; i++) {
		if (get(i, l, r) > 0) res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		upd(s[i]-'a', i, +1);
	}
	cin >> q;
	while (q--) {
		int typ; cin >> typ;
		if (typ == 1) {
			int i;
			char c;
			cin >> i >> c;
			i--;
			//
			upd(s[i]-'a', i, -1);
			s[i] = c;
			upd(s[i]-'a', i, +1);
		} else {
			int l, r;
			cin >> l >> r;
			//
			cout << cnt(l-1, r) << "\n";
		}
	}
	return 0;
}
