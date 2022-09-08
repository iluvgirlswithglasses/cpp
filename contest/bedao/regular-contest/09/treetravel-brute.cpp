
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep  8 11:09:00 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int R = 1e9+7, N = 1e5+7;
int n, parent[N], val[N], res[N];
// root = 0

void add(int &x, int y) {
	x += y;
	if (x >= R) x -= R;
}

void recurse(int u, int a) {
	if (u == 0) return;
	add(val[u], a);
	recurse(parent[u], a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		parent[i] = p;
		val[i] = res[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int u; cin >> u;
		recurse(parent[u], val[u]);
		res[u] = val[u];
	}
	//
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	return 0;
}
