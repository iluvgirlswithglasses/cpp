
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar  9 23:01:18 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define map unordered_map
#define set unordered_set

const int N = 1504, Q = 175007;
// sqr size, colors count, gems count
int n, c, q;
int mat[N][N];
vector<int> col_content[N];	// col_content[c]: colors count of column `c`

void build_col() {
	for (int c = 0; c < n; c++) {
		set<int> s;
		for (int r = 0; r < n; r++) 
			if (mat[r][c] > 0) s.insert(mat[r][c]);
		col_content[c] = vector<int>(s.begin(), s.end());
	}
}

int area(int t, int l, int d, int r) {
	return (r - l + 1) * (d - t + 1);
}

void calc(vector<set<int>> &row_content, const int l, const int r, int &tans, int &lans, int &dans, int &rans, int &maxarea) {
	map<int, int> dct;	// dct[i]: number of times `i` appeared

	int t = 0, d = 0;
	for (; d < n; d++) {
		// elements at the bottom edge are added
		for (int i: row_content[d])
			dct[i]++;

		while (dct.size() == c) {
			// check ans
			if (dct.size() == c && area(t, l, d, r) < maxarea) {
				// new result
				tans = t;
				lans = l;
				dans = d;
				rans = r;
				maxarea = area(t, l, d, r);
			}

			// removes redundant elements at the top
			for (int i: row_content[t]) {
				if (dct[i] == 1) 
					dct.erase(i);
				else 
					dct[i]--;
			}
			t++;
		}
	}
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		memset(mat, 0, sizeof(mat));
		cin >> n >> c >> q;
		for (int i = 0; i < q; i++) {
			int y, x;
			char g;
			cin >> y >> x >> g;
			if ('a' <= g && g <= 'z') mat[y][x] = g - 'a' + 1 + 26;
			if ('A' <= g && g <= 'Z') mat[y][x] = g - 'A' + 1;
		}
		build_col();

		int y0, x0, y1, x1, ans = N * N;

		for (int l = 0; l < n; l++) {
			if (col_content[l].size() == 0) continue;

			set<int> resources;
			vector<set<int>> row_content(n);

			for (int r = l; r < n; r++) {
				if (resources.size() != c) 
					for (int i: col_content[r]) resources.insert(i);
				for (int y = 0; y < n; y++)
					if (mat[y][r] > 0)
						row_content[y].insert(mat[y][r]);

				if (resources.size() == c) {
					if (col_content[r].size() > 0)
						calc(row_content, l, r, y0, x0, y1, x1, ans);
					else
						break;
				}
			}
		}

		cout << "Case #" << t << ": ";
		cout << y0 << " " << x0 << " " << y1 << " " << x1 << " " << ans << "\n";
	}
	return 0;
}
