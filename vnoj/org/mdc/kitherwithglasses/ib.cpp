
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Sep 24 14:47:26 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int S = 502, N = 14, I = 2e9+7;
const int X[4] = {0, 1, 0, -1}, 
          Y[4] = {1, 0, -1, 0};

int  a, b, n;
char m[S][S];
bool visited[S][S];

// doll[0]:   start pos
// doll[n+1]: des pos
pi   doll[N];
int  perm[N];
int  dist[N][N];	// dist[i][j]: distance between doll[i] and doll[j]

void assign() {
	pi des_pos;
	for (int i = 0; i < a; i++)
	for (int j = 0; j < b; j++) {
		switch (m[i][j]) {
			case 'S':
				doll[0] = {i, j}; 
				break;
			case 'D':
				des_pos = {i, j}; 
				break;
			case '!':
				doll[++n] = {i, j}; 
				break;
		}
	}
	doll[n+1] = des_pos;
	//
	for (int i = 0; i <= n+1; i++)
		perm[i] = i;
}

/**
 * @ graph things
 * */
bool legit(int i, int j, int t) {
	int y = i + Y[t], x = j + X[t];
	if (y < 0 || x < 0 || y >= a || x >= b) return false;
	return !visited[y][x] && m[y][x] != '#';
}

void __can_travel(int i, int j, int &cnt) {
	visited[i][j] = true;
	if (m[i][j] == 'S' || m[i][j] == 'D' || m[i][j] == '!') cnt++;
	//
	for (int t = 0; t < 4; t++) if (legit(i, j, t)) {
		__can_travel(i + Y[t], j + X[t], cnt);
	}
}

bool can_travel() {
	int cnt = 0;
	__can_travel(doll[0].st, doll[0].nd, cnt);
	return cnt == n+2;
}

int bfs(pi &src, pi &des) {
	memset(visited, 0, sizeof(visited));
	deque<pi>  q = {src};
	deque<int> d = {0};
	visited[src.st][src.nd] = true;
	//
	while (q.size()) {
		pi  cr    = q.front(); q.pop_front();
		int depth = d.front(); d.pop_front();
		for (int t = 0; t < 4; t++) if (legit(cr.st, cr.nd, t)) {
			int y = cr.st + Y[t], x = cr.nd + X[t];
			if (y == des.st && x == des.nd)
				return depth + 1;
			//
			q.push_back({y, x});
			d.push_back(depth + 1);
			visited[y][x] = true;
		}
	}
	//
	return -I;
}

/**
 * @ drivers
 * */
int calc() {
	int res = 0;
	for (int i = 0; i < n+1; i++) {
		res += dist[ perm[i] ][ perm[i+1] ];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a; i++)
		cin >> m[i];
	assign();
	//
	if (can_travel()) {
		for (int i = 0; i <= n+1; i++)
		for (int j = i+1; j <= n+1; j++) {
			dist[i][j] = dist[j][i] = bfs(doll[i], doll[j]);
		}
		//
		int res = I;
		do {
			res = min(res, calc());
		} while (next_permutation(perm+1, perm+1+n));
		cout << res << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
