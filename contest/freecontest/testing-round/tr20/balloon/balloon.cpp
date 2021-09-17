#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define ll long long

const ll  I = 1e18+7;
int n, m, k; 
vector<ll> a, f, g;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string test; cin >> test;
	ifstream inp("test/input." + test); cin.rdbuf(inp.rdbuf());
	//
	cin >> n >> m >> k;
	a.resize(n); f.resize(n); g.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	g = a;
	//
	for (int i = 1; i < k; i++) {
		// đặc trưng cho bài toán này
		for (int j = 0; j < i; j++) f[j] = -I;
		//
		deque<int> q;
		for (int j = i; j < n; j++) {
			/*
			dp[i][j] = (i+1)*a[j] + *max_element(
				g.begin() + max(0, j-m), g.begin() + j
			);
			*/
			while (q.size() && g[q.back()] <= g[j-1]) q.pop_back();
			q.push_back(j-1);
			if (j - q.front() > m) q.pop_front();
			//
			f[j] = a[j]*(i+1) + g[q.front()];
		}
		swap(f, g);
	}
	cout << *max_element(g.begin(), g.end()) << "\n";
	return 0;
}