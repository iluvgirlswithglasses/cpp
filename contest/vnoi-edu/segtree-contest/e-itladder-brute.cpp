
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep  9 20:50:36 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

const int N = 1e5+7, R = 1e9+7;
int n, q, f[N];

void add(int &x, int y) {
	x += y;
	if (x >= R) x -= R;
}

void mul(int &x, int y) {
	ll r = 1ll*x*y;
	x = r % R;
}

int radd(int x, int y) {
	x += y;
	if (x >= R) x -= R;
	return x;
}

int rmul(int x, int y) {
	ll r = 1ll*x*y;
	return r % R;
}

int bla(ll b, ll l, ll a) {
	return (b - l*a + 1ll*N*R) % R;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	while (q--) {
		int t, l, r, a, b; cin >> t;
		if (t == 1) {
			cin >> l >> r >> a >> b;
			for (int i = l; i <= r; i++)
				add(f[i], radd(bla(b, l, a), rmul(a, i)));
		} else {
			cin >> l >> r;
			int sum = 0;
			for (int i = l; i <= r; i++)
				add(sum, f[i]);
			cout << sum << "\n";
		}
	}
	return 0;
}
