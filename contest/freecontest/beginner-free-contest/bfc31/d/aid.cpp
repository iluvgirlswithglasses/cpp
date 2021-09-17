#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3+7;
int n, k, s, p[N], d[N];
bool visited[N];
vector<int> adj[N], res, route;

/**
 * perf
 * */
void dfs(int i) {
	if (d[i] > d[s] && d[i] <= k) s = i;
	for (int j: adj[i]) {
		d[j] = d[i] + 1;
		dfs(j);
	}
}

void retrieve(int i) {
	res.push_back(i);
	for (int j: adj[i]) {
		if (!visited[j] && k > 0) {
			k -= 1;
			retrieve(j);
			res.push_back(i);
		}
	}
}

void calc() {
	d[1] = 1; s = 1; dfs(1);
	//
	k -= d[s];
	for (int i = s; i != 0; i = p[i]) {
		route.push_back(i);
		visited[i] = true;
	}
	// 
	for (int i = 0; i < route.size(); i++) 
		swap(route[i], route[route.size() - 1 - i]);
	for (int i = 0; i < route.size(); i++)
		retrieve(route[i]);
	//
	cout << res.size() - 1 << endl;
	for (int i = res.size() - 1; i >= 0; i--) 
		cout << res[i] << " "; cout << endl;
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	int t; cin >> t;
	while (t--) {
		//
		cin >> n >> k;
		for (int i = 2; i <= n; i++) {
			cin >> p[i];
			adj[p[i]].push_back(i);
		}
		calc();
		//
		res.clear(); route.clear();
		for (int i = 1; i <= n; i++) {
			visited[i] = false; 
			p[i] = 0; 
			adj[i].clear();
		}
	}
	//
	system("pause");
	return 0;
}
