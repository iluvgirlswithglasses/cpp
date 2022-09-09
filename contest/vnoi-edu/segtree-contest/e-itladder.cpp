
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep  9 19:08:44 2022
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

// [l:r)
int sigma(ll l, ll r) {
	ll res = (r-l) * (l*2 + (r-l-1));
	res >>= 1;
	return res % R;
}

int bla(ll b, ll l, ll a) {
	return (b - l*a + 1ll*N*R) % R;
}

/*
(i-L)A + B = iA - LA + B
u[i]: handles `iA`
v[i]: handles `B - LA`
cnt[i]: returns how many nodes does `i` manage
lef[i]: returns the first node that `i` manage
*/
int n, h, q, f[N<<1], u[N], v[N], cnt[N<<1], lef[N<<1];

void init() {
	h = 32 - __builtin_clz(n);
	for (int i = 0; i < n; i++)
		cnt[i+n] = 1, lef[i+n] = i+1;
	for (int i = n-1; i > 0; i--)
		cnt[i] = cnt[i<<1] + cnt[i<<1|1], lef[i] = lef[i<<1];
}

void assign(int i, int a, int b) {
	/*
	f[i] is assigned
	--> f[i] is increased by (B - LA) + [ lA + (l+1)A + ... + (l+cnt[i]-1)A ]
	--> which == (B - L*A) + [ A*sigma(l, l+cnt[i]) ];
	therefore, u[i] will only store `A`
	sigma value will be calculated locally
	while `B - L*A` will be calculated before it is passed to assign()
	*/
	// add(f[i], rmul(a, sigma(lef[i], lef[i]+cnt[i])));
	add(f[i], b);
	if (i < n) {
		// add(u[i], a);
		add(v[i], b);
	}
}

void pull(int i0) {
	for (int x = h, i = i0>>x; x > 0; i = i0>>(--x)) {
		assign(i<<1  , u[i], v[i]);
		assign(i<<1|1, u[i], v[i]);
		u[i] = v[i] = 0;
	}
}

void push(int i) {
	for (i>>=1; i > 0; i>>=1) {
		f[i] = radd(f[i<<1], f[i<<1|1]);
		// add(f[i], rmul(u[i], sigma(lef[i], lef[i]+cnt[i])));
		add(f[i], v[i]);
	}
}

void update(int l, int r, int a, int b) {
	int l0 = l+=n, r0 = r+=n;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) assign(l++, a, b);
		if (r&1) assign(--r, a, b);
	}
	push(l0); push(r0-1);
}

int query(int l, int r) {
	pull(l+=n); pull((r+=n)-1);
	int res = 0;
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) add(res, f[l++]);
		if (r&1) add(res, f[--r]);
	}
	return res;
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	init();
	while (q--) {
		int t, l, r, a, b; cin >> t;
		if (t == 1) {
			cin >> l >> r >> a >> b;
			update(l-1, r, a, bla(b, l, a));
		} else {
			cin >> l >> r;
			cout << query(l-1, r) << "\n";
		}
	}
	return 0;
}
