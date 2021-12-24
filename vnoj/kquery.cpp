
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec 24 16:27:08 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

struct query {
	int l, r, k, i;
};

const int N = 3e4+7, Q = 2e5+7;
int n, q;
pi arr[N];	// {value, index}
query qry[Q];
int res[Q];	// res[i]: result of query i

/** segtree */
int f[N<<1];

void upd(int i) {
	for (i+=n; i > 0; i>>=1) {
		f[i]++;
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

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// array input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].st;
		arr[i].nd = i;
	}
	sort(arr, arr+n, [](pi& i, pi& j){
		return i.st > j.st;
	});
	// query input
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> qry[i].l >> qry[i].r >> qry[i].k;
		qry[i].i = i;
	}
	sort(qry, qry+q, [](query& i, query& j){
		return i.k > j.k;
	});
	//
	for (int i = 0, j = 0; i < q; i++) {
		while (j < n && arr[j].st > qry[i].k)
			upd(arr[j++].nd);
		res[qry[i].i] = get(qry[i].l - 1, qry[i].r);
	}
	//
	for (int i = 0; i < q; i++)
		cout << res[i] << "\n";
	return 0;
}
