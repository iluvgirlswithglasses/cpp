
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 18 18:20:30 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
time complexity: O(n*mlog(n))
basically can't AC this
*/

#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;


/**
 * @ defs
 * */
struct Result {
	bool has_circle;
	vector<int> weaks;	// luôn đc sort

	Result() {
		has_circle = false;
	}

	bool add_circle(vector<int>& v) {
		if (!has_circle) {
			//
			has_circle = true;
			weaks.assign(v.begin(), v.end());
			sort(weaks.begin(), weaks.end());
		} else {
			// cả 2 thằng phải đều có
			set<int> s(v.begin(), v.end());
			vector<int> u;
			for (int i: weaks) 
				if (s.find(i) != s.end()) u.push_back(i);
			weaks.assign(u.begin(), u.end());
			// không tồn tại cây xung yếu
			if (weaks.size() == 0) {
				has_circle = false;
				return true;
			}
		}
		return false;
	}

	bool has(int i) {
		// trường hợp chưa có circle thì mọi cạnh đều đc trace
		if (!has_circle) return true;
		// ktra xem có cạnh i trong weaks hay k
		int l = 0, r = weaks.size() - 1;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (weaks[m] <= i) {
				l = m;
			} else {
				r = m-1;
			}
		}
		return weaks[l] == i;
	}
} res;

#define pi pair<int, int>
#define st first
#define nd second
const int N = 1004, M = 20004;


/**
 * @ vars
 * */
int n, m;
int v2id[N][N];		// v2id[u][v]: id của cạnh nối 2 đỉnh u & v
pi  edge[M];
vector<int> adj[N];
bool visited[N];


/**
 * @ perf
 * */
bool dfs(int src, int u, vector<int>& trace) {
	for (int v: adj[u]) {
		bool traced = res.has(v2id[u][v]);
		if (traced)
			trace.push_back(v2id[u][v]);
		//
		if (v == src) {
			// detect circle
			if (res.add_circle(trace)) {
				// has 2 or more circles without a shared edge
				// --> break program
				return true;
			}
		} else if (!visited[v]) {
			visited[v] = true;
			if (dfs(src, v, trace)) 
				return true;
			visited[v] = false;
		}
		if (traced)
			trace.pop_back();
	}
	//
	return false;
}


/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
		//
		v2id[u][v] = i;
		edge[i].st = u;
		edge[i].nd = v;
	}
	// calc
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof visited);
		visited[i] = true;
		vector<int> trace;
		if (dfs(i, i, trace)) break;
	}
	// returns
	if (res.has_circle) {
		sort(res.weaks.begin(), res.weaks.end(), [&](int i, int j){
			if (edge[i].st == edge[j].st) 
				return edge[i].nd < edge[j].nd;
			return edge[i].st < edge[j].st;
		});
		//
		cout << res.weaks.size() << "\n";
		for (int i: res.weaks) {
			cout << edge[i].st + 1 << " " << edge[i].nd + 1 << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
