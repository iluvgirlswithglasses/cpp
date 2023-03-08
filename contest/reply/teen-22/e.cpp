
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  8 14:06:28 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

const int N = 14;

/*
x: cells occupied
y: number of ships
z: longest consecutive empty spaces
*/
int rx[N], ry[N], rz[N], 
    cx[N], cy[N], cz[N];
/*
ll in { 2, 3 } - min length of a ship
rr in { 4, 5 } - max length of a ship
*/
int n, ll, rr;

/*
0:  is empty
n:  occupied by ship `n`
*/
int  ans[N][N];
// number of ships under usage
int  used = 0;
// msk[y, x] == true --> must be empty
bool msk[N][N];

/**
 * @ validator
 * */
// check whether a cell is occupied
bool isOccupied(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= n) return false;
	return ans[r][c];
}

bool check() {
	// check if the current matrix is good

	for (int r = 0; r < n; r++) {
		unordered_set<int> ships;
		int occupy = 0;
		int consec = 0, tmp_consec = 0;

		for (int c = 0; c < n; c++) {
			if (ans[r][c] > 0) {
				ships.insert(ans[r][c]);
				occupy++;
				tmp_consec = 0;
			} else {
				consec = max(consec, ++tmp_consec);
			}
		}

		if (rx[r] != occupy || ry[r] != ships.size() || rz[r] != consec) return false;
	}

	// just copy-pasting works
	for (int c = 0; c < n; c++) {
		unordered_set<int> ships;
		int occupy = 0;
		int consec = 0, tmp_consec = 0;
		for (int r = 0; r < n; r++) {
			if (ans[r][c] > 0) {
				ships.insert(ans[r][c]);
				occupy++;
				tmp_consec = 0;
			} else {
				consec = max(consec, ++tmp_consec);
			}
		}

		if (cx[c] != occupy || cy[c] != ships.size() || cz[c] != consec) return false;
	}

	return true;
}

// check if this tile breaks column rules
bool colcheck(int c) {
	unordered_set<int> ships;
	int occupy = 0;
	int consec = 0, tmp_consec = 0;
	for (int r = 0; r < n; r++) {
		if (ans[r][c] > 0) {
			ships.insert(ans[r][c]);
			occupy++;
			tmp_consec = 0;
		} else {
			consec = max(consec, ++tmp_consec);
		}
	}

	if (occupy > cx[c] || ships.size() > cy[c] || consec < cz[c]) return false;
	return true;
}

bool rowcheck(int r) {
	unordered_set<int> ships;
	int occupy = 0;
	int consec = 0, tmp_consec = 0;
	for (int c = 0; c < n; c++) {
		if (ans[r][c] > 0) {
			ships.insert(ans[r][c]);
			occupy++;
			tmp_consec = 0;
		} else {
			consec = max(consec, ++tmp_consec);
		}
	}

	if (occupy > rx[r] || ships.size() > ry[r] || consec < rz[r]) return false;
	return true;
}

/**
 * @ utils
 * */
bool dfs(int r, int c) {
	// check if abandoning this cell would do anything good

	// there's a ship nearby
	if (isOccupied(r-1, c) || isOccupied(r+1, c) || isOccupied(r, c-1) || isOccupied(r, c+1)) 
		return false;

	// assume that i'll turn this cell ans[r][c] on
	// check if that would do anything good
	for (int i = ll; i <= rr; i++) {
		// try to place a ship with length `i` horizontally
		if (c + i <= n) {
			used++;

			bool placed_successfully = true;
			int x = c;

			for (; x < c + i; x++) {
				if (ans[r][x] != 0) {
					placed_successfully = false;
					i = rr+1;
					break;
				}
				ans[r][x] = used;
				if (!colcheck(x) || (x == c && !rowcheck(r))) {
					placed_successfully = false;
					i = rr+1;
					break;
				}
			}

			if (placed_successfully) {
				for (int nxt_x = x+2; nxt_x < n; nxt_x++)
					if (ans[r][nxt_x] == 0) {
						dfs(r, nxt_x);
						if (check()) return true;	// found an answer
					}
				for (int nxt_y = r+1; nxt_y < n; nxt_y++)
					for (int nxt_x = 0; nxt_x < n; nxt_x++)
						if (ans[nxt_y][nxt_x] == 0) {
							dfs(nxt_y, nxt_x);
							if (check()) return true;	// found an answer
						}
			}

			// restore
			used--;
			for (; x >= c; x--) ans[r][x] = 0;
		}
	}

	for (int i = ll; i <= rr; i++) {
		// try to place a ship with length `i` vertically
		if (r + i <= n) {
			used++;

			bool placed_successfully = true;
			int y = r;
			for (; y < r + i; y++) {
				if (ans[y][c] != 0) {
					placed_successfully = false;
					i = rr+1;
					break;
				}
				ans[y][c] = used;
				if (!rowcheck(y) || (y == r && !colcheck(c))) {
					placed_successfully = false;
					i = rr+1;
					break;
				}
			}

			if (placed_successfully) {
				for (int nxt_x = c+2; nxt_x < n; nxt_x++)
					if (ans[r][nxt_x] == 0) {
						dfs(r, nxt_x);
						if (check()) return true;	// found an answer
					}
				for (int nxt_y = r+1; nxt_y < n; nxt_y++)
					for (int nxt_x = 0; nxt_x < n; nxt_x++)
						if (ans[nxt_y][nxt_x] == 0) {
							dfs(nxt_y, nxt_x);
							if (check()) return true;	// found an answer
						}
			}

			// restore
			used--;
			for (; y >= r; y--) ans[y][c] = 0;
		}
	}

	return false;	// havent found the answer
}

void calc() {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			clog << "checking " << r << " " << c << "\n";
			if (dfs(r, c)) return;
		}
	}
}

/**
 * @ drivers
 * */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		memset(ans, 0, sizeof(ans));
		memset(msk, 0, sizeof(msk));

		cin >> n >> ll >> rr;
		for (int i = 0; i < n; i++) cin >> cx[i];
		for (int i = 0; i < n; i++) cin >> cy[i];
		for (int i = 0; i < n; i++) cin >> cz[i];
		for (int i = 0; i < n; i++) cin >> rx[i];
		for (int i = 0; i < n; i++) cin >> ry[i];
		for (int i = 0; i < n; i++) cin >> rz[i];

		calc();
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				cout << (ans[r][c] > 0 ? 1 : 0) << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
