
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 14 19:18:10 2021
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

const int N = 5e5+7;
int n, f[N<<1];

void upd(int l, int r, int v) {
	for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if (l&1) f[l++] += v;
		if (r&1) f[--r] += v;
	}
}

int get(int i) {
	int res = 0;
	for (i+=n; i>0; i>>=1)
		res += f[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
		f[i+n] = s[i] - 'A';
	//
	int k; cin >> k;
	while (k--) {
		int v, l, r;
		cin >> v >> l >> r;
		upd(l-1, r, v);
	}
	//
	for (int i = 0; i < n; i++) {
		char c = (get(i) % 26) + 'A';
		cout << c;
	}
	cout << "\n";
	return 0;
}
