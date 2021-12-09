
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  9 18:07:17 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/**
 * all the idea is from vnoj/dquery and vnoj/vmsalary
 * */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/** 
 * @defs & @vars 
 * 
 * */
const int N = 1e5+7;

struct segtree {
	int n;
	vector<int> f;

	segtree(int size) {
		n = size;
		f.resize(n<<1, 0);
	}

	void insert(int v) {
		for (v += n; v > 0; v >>= 1) {
			f[v]++;
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
};

struct dquery {
	struct element {
		int pre, i;
	};

	struct query {
		int l, r, i;
	};

	int n, m;
	vector<int> last, res;
	vector<element> a;
	vector<query> q;

	dquery(vector<int>& arr, int queries, int* ql, int* qr) {
		n = arr.size();
		m = queries;
		a.resize(n);
		q.resize(m);
		last.resize(n, -1);
		res.resize(m);
		//
		for (int i = 0; i < n; i++) {
			int x = arr[i];
			a[i].pre = last[x], a[i].i = i;
			last[x] = i;
		}
		sort(a.begin(), a.end(), [](element& i, element& j){
			return i.pre < j.pre;
		});
		//
		for (int i = 0; i < m; i++) {
			q[i].l = ql[i], q[i].r = qr[i];
			q[i].i = i;
		}
		sort(q.begin(), q.end(), [](query& i, query& j){
			return i.l > j.l;
		});
		//
		segtree f(n);
		int p = n-1;
		for (query& q: q) {
			while (a[p].pre >= q.l)
				f.insert(a[p--].i);
			//
			res[q.i] = (q.r - q.l + 1) - f.get(q.l, q.r+1);
		}
	}
};

/** 
 * @vars 
 * 
 * */
int n, c[N], flat_l[N], flat_r[N];
vector<int> adj[N];
vector<int> flat;

/** 
 * @perf 
 * 
 * */
void compress() {
	set<int> s(c, c+n);
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
	}
}

void dfs(int u, int p) {
	// flaterize the tree
	flat_l[u] = flat.size();
	flat.push_back(c[u]);
	for (int v: adj[u]) 
		if (v != p) dfs(v, u);
	flat_r[u] = flat.size();
	flat.push_back(c[u]);
}

/** 
 * @drivers 
 * 
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	compress();
	dfs(0, -1);
	//
	dquery ans(flat, n, flat_l, flat_r);
	for (int i: ans.res) {
		cout << i << "\n";
	}
	return 0;
}
