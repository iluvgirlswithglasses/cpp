
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 22 17:06:49 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

const int N = 2e5+7;
int n, a[N];
vector<int> adj[N];

multiset<int> dfs(int u) {
	if (adj[u].size() == 0) {
		multiset<int> s;
		s.insert(a[u]);
		return s;
	}
	//
	vector<multiset<int>> child;
	// kế thừa
	for (int v: adj[u])
		child.push_back(dfs(v));
	// merge
	sort(all(child), [](multiset<int>& i, multiset<int>& j){
		return i.size() > j.size();
	});
	for (int i = 1; i < child.size(); i++)
		child[0].insert(all(child[i]));
	// thêm `u` vào lis
	multiset<int>::iterator p = child[0].lower_bound( a[u] );
	if (p != child[0].end())
		child[0].erase(p);
	child[0].insert( a[u] );
	//
	return child[0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1, p; i <= n; i++) {
		cin >> a[i] >> p;
		adj[p].push_back(i);
	}
	//
	cout << dfs(1).size() << "\n";
	//
	return 0;
}
