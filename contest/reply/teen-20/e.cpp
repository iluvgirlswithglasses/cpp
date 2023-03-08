
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  8 17:29:57 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int ROW = 502, N = ROW * ROW * 2, I = 1e9+7, R = 1e9+7;
int n, m, nodes, stt, des;

struct PentagonVertice {
	
	int i, j, k, id;

	PentagonVertice() {
		i = j = k = 0;
		id = -1;
	}

	PentagonVertice(int _i, int _j, int _k) {
		i = _i, j = _j, k = _k;
		id = toInt();
	}

	int toInt() {
		if (i < 0 || j < 0 || i >= n || j >= m) return -1;
		return i * (m<<1) + (j<<1) + k;
	}

	void prf() {
		cout << i << " " << j << " " << k << "\n";
	}

	/**
	 * @ adj
	 * */
	vector<int> getAdj() {
		if (i&1) {
			if (j&1)
				if (k&1)
					return rightAdj();
				else
					return leftAdj();
			else
				if (k&1)
					return downAdj();
				else
					return topAdj();
		} else {
			if (j&1)
				if (k&1)
					return downAdj();
				else
					return topAdj();
			else 
				if (k&1)
					return rightAdj();
				else
					return leftAdj();
		}
	}

	vector<int> leftAdj() {
		vector<PentagonVertice> candidates = {
			PentagonVertice( i  , j-1, 0 ),	// 10 hr
			PentagonVertice( i  , j-1, 1 ),	// 7  hr
			PentagonVertice( i  , j  , 1 ),	// 3  hr
			PentagonVertice( i-1, j  , 1 ),	// 12 hr
			PentagonVertice( i+1, j  , 0 ),	// 6  hr
		};
		return candidatesToInt(candidates);
	}

	vector<int> rightAdj() {
		vector<PentagonVertice> candidates = {
			PentagonVertice( i  , j+1, 0 ),	// 2  hr
			PentagonVertice( i  , j+1, 1 ),	// 4  hr
			PentagonVertice( i  , j  , 0 ),	// 9  hr
			PentagonVertice( i-1, j  , 1 ),	// 12 hr
			PentagonVertice( i+1, j  , 0 ),	// 6  hr
		};
		return candidatesToInt(candidates);
	}

	vector<int> topAdj() {
		vector<PentagonVertice> candidates = {
			PentagonVertice( i-1, j  , 0 ),	// 11 hr
			PentagonVertice( i-1, j  , 1 ), // 1  hr
			PentagonVertice( i  , j-1, 1 ), // 9  hr
			PentagonVertice( i  , j+1, 0 ),	// 3  hr
			PentagonVertice( i  , j  , 1 ),	// 6  hr
		};
		return candidatesToInt(candidates);
	}

	vector<int> downAdj() {
		vector<PentagonVertice> candidates = {
			PentagonVertice( i+1, j  , 0 ),	// 7  hr
			PentagonVertice( i+1, j  , 1 ), // 5  hr
			PentagonVertice( i  , j-1, 1 ), // 9  hr
			PentagonVertice( i  , j+1, 0 ),	// 3  hr
			PentagonVertice( i  , j  , 0 ),	// 12 hr
		};
		return candidatesToInt(candidates);
	}

	vector<int> candidatesToInt(vector<PentagonVertice> &candidates) {
		vector<int> ans;
		for (int i = 0; i < 5; i++)
			if (candidates[i].id != -1) ans.push_back(candidates[i].id);
		return ans;
	}
} vts[N];			// vts[i]: PentagonVertice of node with id `i`

string dat[ROW];
vector<int> adj[N];	
int wei[N];			// wei[i]: weight of node `i`

void buildGraph() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 2; k++) {
				nodes++;
				PentagonVertice u(i, j, k);
				vts[u.id] = u;
				vector<int> nxt = u.getAdj();
				for (int v: nxt) adj[u.id].push_back(v);

				char weight = dat[i][j<<1|k];
				if (weight == 'S')
					stt = u.id, wei[u.id] = I;
				else if (weight == 'D')
					des = u.id, wei[u.id] = I;
				else
					wei[u.id] = weight - '0';
			}
		}
	}

	/*
	for (int i = 0; i < nodes; i++) {
		vts[i].prf();
		for (int j: adj[i]) vts[j].prf();
		cout << "\n";
	}
	*/
}

/**
 * @ dijkstra
 * 
 * the implementation of this dijkstra is similar to 
 * ./vnoj/old-sol/b211109/dhfrbus/bus.cpp
 * */
struct Dijnode {
	int u, w;	// current node, current min weight
	int ans;	// the node that has been upgraded (-1 if none has been upgraded)

	bool operator < (const Dijnode &d) const {
		if (w == d.w) return ans > d.ans;	// smaller ans is prioritized
		return w < d.w; // now priority queue will get the one with the max `w`
	}

	Dijnode(int _u, int _w, int _ans) {
		u = _u, w = _w, ans = _ans;
	}
};

int dijkstra() {
	priority_queue<Dijnode, vector<Dijnode>> q;
	q.push(Dijnode(stt, I, -1));
	// d[0]: without upgrade
	// d[1]: with upgrade
	vector<vector<int>> d(2, vector<int>(nodes, 0));
	d[0][stt] = d[1][stt] = I;

	while (q.size()) {
		Dijnode a = q.top(); q.pop();
		bool upgraded = a.ans > -1;

		for (int v: adj[a.u]) {
			if (v == des) return a.ans;

			int nxtw = min(a.w, wei[v]);
			if (upgraded && nxtw > d[1][v]) {
				d[1][v] = nxtw;
				q.push(Dijnode(v, nxtw, a.ans));
			} else if (!upgraded) {
				// dont upgrade this node
				if (nxtw > d[0][v]) {
					d[0][v] = nxtw;
					q.push(Dijnode(v, nxtw, -1));
				}

				// upgrade this node
				if (a.w > d[1][v]) {
					d[1][v] = a.w;
					q.push(Dijnode(v, a.w, v));
				}
			}
		}
	}

	return -1;	// wont happens
}

/**
 * @ drivers
 * */
void read() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> dat[i];
	for (int i = 0; i < N; i++)
		adj[i].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		read();
		buildGraph();
		cout << "Case #" << t << ": ";
		int ans = dijkstra();
		if (ans == -1) cout << "-1\n";
		else vts[ans].prf();
	}
	return 0;
}
