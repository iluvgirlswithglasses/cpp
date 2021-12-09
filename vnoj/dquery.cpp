
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  9 13:42:09 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/**
 * if I can solve this, I can solve fc082_treecolor
 * */

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @ defs
 * */
const int I = 1e6+7, N = 3e4+7, Q = 2e5+7;

struct query {
	int l, r, i;
};

struct element {
	int pre, i;
};

/**
 * @ vars
 * */
int n, m, last[I], res[Q];
query q[Q];
element a[N];

/**
 * @ segtree
 * */
int f[N<<1];

void insert(int p) {
	for (p+=n; p > 0; p>>=1) {
		f[p]++;
	}
}

int get(int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[l++];
		if (r&1) res += f[--r];
	}
	return res;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[i].pre = last[x], a[i].i = i;
		last[x] = i;
	}
	sort(a+1, a+1+n, [](element& i, element& j){
		return i.pre < j.pre;
	});
	//
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].i = i;
	}
	sort(q+1, q+1+m, [](query& i, query& j){
		return i.l > j.l;	// sort từ phải sang trái
	});
	//
	int p = n;
	for (int i = 1; i <= m; i++) {
		while (a[p].pre >= q[i].l) 
			insert(a[p--].i - 1);	// bây giờ xài thằng này là trùng đó
		//
		res[q[i].i] = (q[i].r - q[i].l + 1) - get(q[i].l-1, q[i].r);
	}
	//
	for (int i = 1; i <= m; i++)
		cout << res[i] << " ";
	cout << "\n";
	return 0;
}
