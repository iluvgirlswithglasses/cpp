
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
#define pi pair<int, int>
#define st first
#define nd second
const int N = 1002, M = 20002;

int n, m;
int v2id[N][N];		// v2id[u][v]: id của cạnh nối 2 đỉnh u & v
pi  edge[M];
vector<int> adj[N];
bool visited[N];

bool __has[M];
int  __cnt;
struct Result {
	bool has_circle;

	Result() {
		has_circle = false;
	}

	bool add_circle(vector<int>& v) {
		if (!has_circle) {
			//
			has_circle = true;
			__cnt = v.size();
			for (int i: v) __has[i] = true;

		} else {
			// cả 2 thằng phải đều có
			set<int> s(v.begin(), v.end());	// s chỉ chứa những index đã có trong __has
			for (int i = 0; i < m; i++) {
				if (__has[i] && s.find(i) == s.end()) {
					__has[i] = false;
					__cnt--;
				}
			}
			// không tồn tại cây xung yếu
			if (__cnt == 0) {
				has_circle = false;
				return true;
			}
		}
		return false;
	}

	vector<int> get() {
		vector<int> r;
		for (int i = 0; i < m; i++) 
			if (__has[i]) r.push_back(i);
		return r;
	}
} res;


/**
 * @ perf
 * */
bool dfs(int src, int u, vector<int>& trace) {
	for (int v: adj[u]) {
		bool traced = !res.has_circle || __has[ v2id[u][v] ];
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
		vector<int> weaks = res.get();
		sort(weaks.begin(), weaks.end(), [&](int i, int j){
			if (edge[i].st == edge[j].st) 
				return edge[i].nd < edge[j].nd;
			return edge[i].st < edge[j].st;
		});
		//
		cout << weaks.size() << "\n";
		for (int i: weaks) {
			cout << edge[i].st + 1 << " " << edge[i].nd + 1 << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
