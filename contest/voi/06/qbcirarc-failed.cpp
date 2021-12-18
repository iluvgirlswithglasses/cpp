
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
	vector<int> weaks;

	Result() {
		has_circle = false;
	}

	bool add_circle(vector<int>& v) {
		if (!has_circle) {
			//
			has_circle = true;
			for (int i: v) weaks.push_back(i);
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
bool dfs(int u, vector<int>& trace) {
	for (int v: adj[u]) {
		trace.push_back(v2id[u][v]);
		if (visited[v]) {
			// detect circle
			if (res.add_circle(trace)) 
				// has 2 or more circles without a shared edge
				// --> break program
				return true;
		} else {
			visited[v] = true;
			if (dfs(v, trace)) 
				return true;
			visited[v] = false;
		}
		trace.pop_back();
	}
	//
	return false;
}


/**
 * @ drivers
 * */
vector<string> edges2str() {
	vector<string> r;
	for (int i: res.weaks) {
		string s = to_string(edge[i].st + 1) + " " + to_string(edge[i].nd + 1);
		r.push_back(s);
	}
	sort(r.begin(), r.end());
	return r;
}

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
		if (dfs(i, trace)) break;
	}
	// returns
	if (res.has_circle) {
		cout << res.weaks.size() << "\n";
		vector<string> prf = edges2str();
		for (string s: prf) cout << s << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
