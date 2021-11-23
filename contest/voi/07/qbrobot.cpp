
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 23 11:45:29 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// I'm dead hungry rn

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/** defs */
#define pi pair<int, int>
#define st first
#define nd second
const int N = 502;
const int I = 2e9+7;

/** vars */
int n, m, t[N][N], c[N][N];
bool powered[N];
vector<int> adj[N];

/** dijkstra */
struct pack {
	// u: vertice
	// t: time to vertice
	// c: current needed energy
	// w: needed energy volume
	int u, t, c, w;

	// trick the priority queue
	bool operator < (const pack& i) const {
		return t > i.t;
	}

	static pack mkpack(int _u, int _t, int _c, int _w) {
		pack p;
		p.u = _u; p.t = _t; p.c = _c; p.w = _w;
		return p;
	}
};

int dijkstra() {
	priority_queue<pack> q;
	q.push(pack::mkpack(0, 0, 0, 0));
	vector<int> d(n, I);
	d[0] = 0;
	vector<int> res;	// all the `w`
	//
	while (q.size()) {
		pack p = q.top(); q.pop();
		if (d[n-1] < p.t) break;
		//
		for (int v: adj[p.u]) {
			int time = p.t + t[p.u][v];
			int cost = p.c + c[p.u][v];
			int need = max(p.w, cost);
			if (powered[v]) 
				cost = 0;
			//
			if (v == n-1) {
				if (time < d[v]) {
					res.clear();
					res.push_back(need);
				} else if (time == d[v]) {
					res.push_back(need);
				}
			}
			//
			if (time <= d[v]) {
				d[v] = time;
				q.push(pack::mkpack(v, time, cost, need));
			}
		}
	}
	//
	return *min_element(res.begin(), res.end());
}

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> powered[i];
	cin >> m;
	while (m--) {
		int i, j, ti, co;
		cin >> i >> j >> ti >> co;
		i--; j--;
		adj[i].push_back(j);
		adj[j].push_back(i);
		//
		t[i][j] = ti;
		t[j][i] = ti;
		c[i][j] = co;
		c[j][i] = co;
	}
	//
	cout << dijkstra() << "\n";
	return 0;
}
