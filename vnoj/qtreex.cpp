
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 14 10:24:19 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @vars & @defs
 * */
#define all(c) c.begin(), c.end()
#define ll long long

struct pi {
	int st, nd;

	pi() {
		st = 0, nd = 0;
	}

	pi(int a, int b) {
		st = a, nd = b;
	}

	bool operator < (const pi& i) const {
		return st < i.st;
	}
};

const int N = 1e4+7, I = 1e9+7;
int n;
vector<vector<pi>> adj;	// adj[u]: {adj vertice, weight of the edge}
vector<pi> edge;
int parent[N];
int weight[N];			// weight[i]: the weight of the edge that connect `i` and its parent
int childCnt[N];		// childCnt[i]: the length of the longest line that `i` can be the head of

/**
 * @utils
 * */
int genChildCnt(int u, int p) {
	parent[u] = p;
	if (u != 1 && adj[u].size() == 1) {
		childCnt[u] = 0;
		return 1;
	}
	int mx = 0;
	for (pi& v: adj[u]) if (v.st != p) {
		weight[v.st] = v.nd;
		mx = max(mx, genChildCnt(v.st, u));
	}
	childCnt[u] = mx;
	return mx + 1;
}


/**
 * @main
 * */
struct LCA {

	struct SegTree {
		int n;
		vector<pi> f;	// f[i]: {depth, index}

		void init(vector<int>& euler, vector<int>& depth) {
			n = euler.size();
			f.resize(n<<1);
			for (int i = 0; i < n; i++)
				f[i+n] = pi(depth[euler[i]], euler[i]);
			for (int i = n-1; i > 0; i--)
				f[i] = min(f[i<<1], f[i<<1|1]);
		}

		int get(int l, int r) {
			pi res = pi(I, 0);
			for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
				if (l&1) res = min(res, f[l++]);
				if (r&1) res = min(res, f[--r]);
			}
			return res.nd;
		}
	};

	vector<int> euler, first, depth;
	SegTree st;

	void init() {
		euler.reserve(n<<1);
		first.resize(n+1);
		depth.resize(n+1);
		dfs(1, 0);
		st.init(euler, depth);
	}

	void dfs(int u, int d) {
		first[u] = euler.size();
		depth[u] = d;
		euler.push_back(u);
		for (pi& v: adj[u]) if (v.st != parent[u]) {
			dfs(v.st, d+1);
			euler.push_back(u);
		}
	}

	int get(int a, int b) {
		if (first[a] > first[b]) swap(a, b);
		return st.get(first[a], first[b]+1);
	}
};

struct HLD {

	struct SegTree {
		/*
		f[i]: 
			stores the weight of the edge that connect
			the node with index `i` in the flatten tree 
			and its parent
		*/
		vector<int> f;
		/*
		d[i] == true means:
			f[i] is requested by the NEGATE command
			it has updated itself, but it children have not
		*/
		vector<bool> d;
		// h: the height of the this tree
		int h;

		void init(vector<int>& index) {
			h = 32 - __builtin_clz(n);
			f.resize(n<<1, 0);
			d.resize(n, false);
			for (int i = 1; i <= n; i++)
				f[index[i] + n] = weight[i];
			for (int i = n-1; i > 0; i--)
				f[i] = max(f[i<<1], f[i<<1|1]);
		}

		void assign(int i) {
			f[i] = -f[i];
			if (i < n) d[i] = d[i] ^ 1;	// switch NEGATE status
		}

		void push_down(int i) {
			// push every information that is stacked on node i
			for (int x = h-1, idx = i>>x; x > 0; x--, idx = i>>x) {
				if (d[idx]) {
					assign(idx<<1);
					assign(idx<<1|1);
					d[idx] = 0;
				}
			}
		}

		void push_up(int i) {
			// push the information of node `i` to its parents
			for (i>>=1; i > 0; i>>=1) {
				if (d[i])
					f[i] = max(-f[i<<1], -f[i<<1|1]);
				else
					f[i] = max(+f[i<<1], +f[i<<1|1]);
			}
		}

		void negate(int l, int r) {
			l += n; int l0 = n;
			r += n; int r0 = r;
			for (; l < r; l>>=1, r>>=1) {
				if (l&1) assign(l++);
				if (r&1) assign(--r);
			}
			push_up(l0);
			push_up(r0);
		}

		void upd(int i, int v) {
			push_down(i+=n);
			f[i] = v;
			push_up(i);
		}

		int get(int l, int r) {
			l += n; push_down(l);
			r += n; push_down(r-1);
			//
			int res = -I;
			for (; l < r; l>>=1, r>>=1) {
				if (l&1) res = max(res, f[l++]);
				if (r&1) res = max(res, f[--r]);
			}
			return res;
		}
	};

	int crChain = 0;
	vector<int> head;		// head[i]: the head vertice of chain `i`
	vector<int> chain;		// chain[i]: the chain that vertice `i` belongs to
	int crIndex = 0;
	vector<int> index;		// index[i]: the index of `i` in the flatten tree

	SegTree st;
	LCA lca;

	void init() {
		head.resize(n, 0);
		chain.resize(n+1, 0);
		index.resize(n+1, 0);
		build(1);
		st.init(index);
		lca.init();
	}

	void build(int u) {
		if (head[crChain] == 0) head[crChain] = u;
		chain[u] = crChain;
		index[u] = crIndex++;
		//
		int mx = -1, mxCnt = -1;
		for (pi& v: adj[u]) if (v.st != parent[u]) {
			if (childCnt[v.st] > mxCnt) mx = v.st, mxCnt = childCnt[v.st];
		}
		if (mxCnt > -1) build(mx);
		//
		for (pi& v: adj[u]) if (v.st != parent[u] && v.st != mx) {
			crChain++;
			build(v.st);
		}
	}

	void change(int i, int v) {
		st.upd(index[i], v);
	}

	int linearQuery(int a, int b) {
		// index[b] > index[a]
		int mx = -I;
		while (true) {
			if (chain[a] == chain[b]) {
				return max(mx, st.get(index[a]+1, index[b]+1));
			} else {
				int hd = head[ chain[b] ];
				mx = max(mx, st.get(index[hd], index[b]+1));
				b = parent[hd];
			}
		}
	}

	int query(int a, int b) {
		if (a == b) return 0;
		int c = lca.get(a, b);
		return max(
			linearQuery(c, a),
			linearQuery(c, b)
		);
	}

	void linearNegate(int a, int b) {
		while (true) {
			if (chain[a] == chain[b]) {
				st.negate(index[a]+1, index[b]+1);
				return;
			} else {
				int hd = head[ chain[b] ];
				st.negate(index[hd], index[b]+1);
				b = parent[hd];
			}
		}
	}

	void negate(int a, int b) {
		int c = lca.get(a, b);
		if (c == a) {
			linearNegate(c, b);
		} else if (c == b) {
			linearNegate(c, a);
		} else {
			linearNegate(c, a);
			linearNegate(c, b);
		}
	}
};


/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		adj.clear();
		adj.resize(n+1, vector<pi>());
		edge.resize(n);
		for (int i = 1, a, b, c; i <= n-1; i++) {
			cin >> a >> b >> c;
			adj[a].push_back(pi(b, c));
			adj[b].push_back(pi(a, c));
			edge[i] = pi(a, b);
		}
		genChildCnt(1, 0);
		HLD hld;
		hld.init();
		while (true) {
			string t; cin >> t;
			if (t == "DONE") 
				break;
			int a, b; 
			cin >> a >> b;
			if (t == "CHANGE") {
				if (edge[a].st == parent[edge[a].nd])
					hld.change(edge[a].nd, b);
				else
					hld.change(edge[a].st, b);
			} else if (t == "NEGATE") {
				hld.negate(a, b);
			} else if (t == "QUERY") {
				cout << hld.query(a, b) << "\n";
			}
		}
	}
	return 0;
}
