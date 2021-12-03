
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec  3 19:37:21 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

/*
res = min(
	ai * aj, bi * bj
)

th: ai * aj <= bi * bj
--> ai / bi <= bj / aj

th: bi * bj <= ai * aj
--> bi / aj <= ai / bj

đầu tiên, tính hết giá trị chia rồi nén
sau đó, với th a:
	lấy rank giá trị chia làm index cho segtree,
	lôi đầu thằng có aj to nhất ra
tương tự với th b
*/

/**
 * @defs
 * */
const int N = 1e5+7;
#define ll long long

struct segtree {
	int n;
	vector<int> f;

	segtree(int s) {
		n = s;
		f.resize(n<<1, 0);
	}

	void upd(int p, int v) {
		for (p+=n; p > 0; p>>=1)
			f[p] = max(f[p], v);
	}

	int get(int l) {
		int res = 0, r = n;
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) res = max(res, f[l++]);
			if (r&1) res = max(res, f[--r]);
		}
		return res;
	}
};

/**
 * @vars
 * */
int n, a[N], b[N];
int a_over_b[N], b_over_a[N];

/**
 * @perf
 * */
void compress() {
	vector<double> d;
	for (int i = 0; i < n; i++)
		d.push_back((double) a[i] / b[i]);
	for (int i = 0; i < n; i++)
		d.push_back((double) b[i] / a[i]);
	set<double> s(d.begin(), d.end());
	d.assign(s.begin(), s.end());
	//
	for (int i = 0; i < n; i++) {
		a_over_b[i] = lower_bound(d.begin(), d.end(), (double) a[i] / b[i]) - d.begin();
		b_over_a[i] = lower_bound(d.begin(), d.end(), (double) b[i] / a[i]) - d.begin();
	}
}

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	compress();
	//
	segtree fa(n<<1);
	segtree fb(n<<1);
	ll res = 0;
	//
	for (int i = 0; i < n; i++) {
		ll cr = max(
			(ll) fa.get(a_over_b[i]) * a[i],
			(ll) fb.get(b_over_a[i]) * b[i]
		);
		//
		res = max(res, cr);
		fa.upd(b_over_a[i], a[i]);
		fb.upd(a_over_b[i], b[i]);
	}
	//
	cout << res << "\n";
	return 0;
}
