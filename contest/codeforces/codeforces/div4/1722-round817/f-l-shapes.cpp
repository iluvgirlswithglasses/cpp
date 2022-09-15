
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 15 18:01:52 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
using namespace std;

#define all(c) c.begin(), c.end()
#define pi pair<int, int>
#define st first
#define nd second
const int N = 54;
int n, m;
char row[N];
bool grid[N][N];
bool used[N][N];

// adj list in relative position
// the first cell of a shape is the top-left cell (top is prioritied)
const pi adj[3*4] = {
	{0, 0}, {+1, +0}, {+1, +1},
	{0, 0}, {+1, -1}, {+1, +0},
	{0, 0}, {+0, +1}, {+1, +1},
	{0, 0}, {+1, +0}, {+0, +1}
};

// if `x, y` is the first position of the shape
// then these relative cells need to be empty
const pi emp[12*4] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {2, -1}, {1, -1}, {0, -1},
	{-1, -2}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {2, 1}, {2, 0}, {2, -1}, {2, -2}, {1, -2}, {0, -2},
	{-1, -1}, {-1, 0}, {-1, 1}, {-1, 2}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}, {1, -1}, {0, -1},
	{-1, -1}, {-1, 0}, {-1, 1}, {-1, 2}, {0, 2}, {1, 2}, {1, 1}, {2, 1}, {2, 0}, {2, -1}, {-1, -1}, {0, -1}
};

bool found(int t, int i, int j) {
	for (int l = t*3; l < (t+1)*3; l++)
		if (!grid[i + adj[l].st][j + adj[l].nd]) return false;
	return true;
}

bool safe(int t, int i, int j) {
	for (int l = t*3; l < (t+1)*3; l++)
		if (used[i + adj[l].st][j + adj[l].nd]) return false;
	for (int l = t*12; l < (t+1)*12; l++)
		if (grid[i + emp[l].st][j + emp[l].nd]) return false;
	return true;
}

void mark(int t, int i, int j) {
	for (int l = t*3; l < (t+1)*3; l++)
		used[i + adj[l].st][j + adj[l].nd] = true;
}

bool check(int t) {
	// case `t` has two adj tiles: adj[t<<1] and adj[t<<1|1]
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) if (found(t, i, j)) {
		if (!safe(t, i, j)) return false;
		mark(t, i, j);
	}
	return true;
}

const char* calc() {
	for (int i = 0; i < 4; i++)
		if (!check(i)) return "NO\n";
	// remove stray tiles
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (grid[i][j] && !used[i][j]) return "NO\n";
	return "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(grid, 0, sizeof(grid));
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= n; i++) {
			cin >> row+1;
			for (int j = 1; j <= m; j++)
				grid[i][j] = (row[j] == '*');
		}
		cout << calc();
	}
	return 0;
}
