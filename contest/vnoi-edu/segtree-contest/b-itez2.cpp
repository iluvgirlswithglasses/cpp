
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep  4 16:14:55 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
const int N = 1e5+7;
int n, q;
ll  f[N<<1];

void upd(int x, int v) {
	f[x+=n] = v;
	for (x>>=1; x > 0; x>>=1)
		f[x] = f[x<<1] + f[x<<1|1];
}

ll get(int l, int r) {
	ll res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[l++];
		if (r&1) res += f[--r];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) 
			upd(a-1, b);
		else
			cout << get(a-1, b) << "\n";
	}
	return 0;
}
