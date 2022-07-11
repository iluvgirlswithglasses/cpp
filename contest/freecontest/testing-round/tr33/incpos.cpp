
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jul 10 23:26:50 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
given the array `a[]` and `q` queries
for each query
increase `a[l:r]` by `x`
then print the number of this occurrences: `a[i] > a[i+1]`
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 2e5+7;
// cnt: count of occurrences
int	n, q, cnt;
// f[]: simple upd-N-qry-1 segtree
ll f[N<<1];
// pos[i]: returns true if occurs `a[i] > a[i+1]`
bool pos[N];

struct segtree {

	void upd(int l, int r, ll v) {
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) f[l++] += v;
			if (r&1) f[--r] += v;
		}
	}

	ll get(int p) {
		ll r = 0;
		for (p+=n; p > 0; p>>=1)
			r += f[p];
		return r;
	}
} st;

void check(int i) {
	if (st.get(i) > st.get(i+1) && !pos[i]) {
		cnt++;
		pos[i] = true;
	} else if (st.get(i) <= st.get(i+1) && pos[i]) {
		cnt--;
		pos[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) 
		cin >> f[i+n];
	for (int i = 0; i < n-1; i++) if (f[n+i] > f[n+i+1]) {
		cnt++;
		pos[i] = true;
	}
	//
	while (q--) {
		int l, r, v; cin >> l >> r >> v;
		st.upd(--l, r--, v);
		if (l > 0) check(l-1);	// left
		if (r < n-1) check(r);	// right
		cout << cnt << "\n";
	}
	return 0;
}
