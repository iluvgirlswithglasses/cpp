
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 18 16:53:23 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
liên thông toàn phần 
--> mỗi đỉnh có bậc vào == bậc ra 

đồ thị không liên thông toàn phần
--> có ít nhất 1 đỉnh có bậc vào == 0

vậy mục tiêu là nối đỉnh có bậc vào to nhất
vào một đỉnh khác có bậc vào == 0

rồi kiểm tra xem đồ thị liên thông toàn phần hay chưa
nếu rồi, in ra cạnh nối

nếu chưa thì in NO
*/

/** @ defs & vars */
const int N = 2004;
int n, m;
vector<int> adj[N];

/** @ in and out */
int fi[N], fo[N];
bool visited[N];

void dfs(int u, int& cnt) {
	visited[u] = true;
	fi[u]++;
	cnt++;
	//
	for (int i: adj[u]) 
		if (!visited[i]) dfs(i, cnt);
}

void get_access_degree() {
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof visited);
		int cnt = 0;
		dfs(i, cnt);
		// trừ trường hợp tự thăm chính nó
		fo[i] = cnt-1;
		fi[i]--;
	}
}

/** @ drivers */
bool check() {
	for (int i = 0; i < n; i++)
		if (fi[i] != n-1 || fo[i] != n-1) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u-1].push_back(v-1);
	}
	//
	get_access_degree();
	int u = max_element(fi, fi+n) - fi;	// bậc vào cao nhất
	int v = find(fi, fi+n, 0) - fi;		// bậc vào == 0
	adj[u].push_back(v);
	//
	memset(fi, 0, sizeof fi);
	memset(fo, 0, sizeof fo);
	get_access_degree();
	if (check()) {
		cout << "YES\n" << u+1 << " " << v+1 << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
