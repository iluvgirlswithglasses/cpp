
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 23 08:41:26 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

inline ll nC2(ll n) {
	return (n * (n - 1)) >> 1;
}

const int N = 1e5+7;

// tính chẵn lẻ của a[l:r] == tính chẵn lẻ của (prefix sum) p[r] - p[l-1]
int n, q, a[N], p[N];

struct segtree {

	// f[0][i]: segtree cho biết trong p[l:r) có bao nhiêu số chẵn
	// f[1][i]: segtree .................................. số lẻ
	// --> để biết số cách chọn, chỉ cần gọi nC2();
	ll f[2][N<<1];

	// flip[i] --> các node f[?][i] bị thay đổi tính chẵn lẻ
	bool flip[N<<1];

	void build() {
		for (int i = 0; i < n; i++)
			f[ p[i]&1 ][ n + i ] = 1;
		for (int i = n-1; i > 0; i--)
			f[0][i] = f[0][i<<1] + f[0][i<<1|1],
			f[1][i] = f[1][i<<1] + f[1][i<<1|1];
	}

	void assign(int i) {

	}

	void push(int i) {

	}

	void pull(int i0) {

	}

	void upd(int l, int r, int v) {
		if ((v&1) == (a[l]&1)) 
			return;	// tính chẵn lẻ không đổi
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) assign(l++);
			if (r&1) assign(--r);
		}
	}

	ll getchance(int i) {
		return nC2(f[0][i]) + nC2(f[1][i]);
	}

	ll query(int l, int r) {
		ll res = 0;
		pull(l+=n);
		pull((r+=n) - 1);
		//
		for (; l < r; l>>=1, r>>=1) {
			if (l&1) res += getchance(l++);
			if (r&1) res += getchance(--r);
		}
		return res;
	}
} st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		p[i] = p[i-1] + a[i];
	n++;
	st.build();
	//
	while (q--) {
		int k, a, b;
		cin >> k >> a >> b;
		if (k == 1)
			st.upd(a, n, b);
		else
			cout << st.query(a-1, b+1) << "\n";
	}
	return 0;
}
