
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Mar  7 21:07:39 2023
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
#include <set>
#include <map>
using namespace std;

// because all enemies on a row will be taken damage at once
// i only need to keep track of the tankiest one of each row
// and screw all the others

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int R = 102, C = 202, D = 2507, HP = 25007;
int r, c, n, s;
int d, h;
int grid[R][C];

int calc_dmg(int d, int f, int h) {
	// d: const dmg
	// f: distance
	// h: dmg mod
	return max(0, d - f * h);
}

int cr(int row, int turn) {
	int a = row - turn;
	return ((a % r) + r) % r;
}

ll calc() {
	deque<pair<int, int>> q;	// { row at turn 0, current hp }
	// init deque
	for (int y = 0; y < r; y++) {
		int mx = *max_element(grid[y], grid[y] + c);
		if (mx > 0) q.push_back({y, mx});
	}
	int turn = 0;
	ll  ans = 0;
	// this emulate a turn
	while (true) {

		// shoot phase
		int remaining_shots = s;
		while (remaining_shots > 0) {

			if (q.empty()) {
				int this_round_shots = s - remaining_shots;
				return ans + this_round_shots;
			}

			pair<int, int> &p = q.front();
			int dmg = calc_dmg(d, cr(p.st, turn), h),	// damage in 1 shot
			    mxdmg = remaining_shots * dmg;			// max damage can be dealt till the end of this turn

			if (dmg == 0) break;						// cant deal dmg --> move to next turn

			if (mxdmg < p.nd) {
				remaining_shots = 0;
				p.nd -= mxdmg;
			} else {
				int shot_needed = (p.nd + dmg - 1) / dmg;	// ceil(p.nd / dmg)
				remaining_shots -= shot_needed;
				q.pop_front();
			}
		}

		// check round
		ans += s;
		if (q.empty()) return ans;

		// move phase
		turn++;
		pair<int, int> f = q.front();
		if (cr(f.st, turn) == r - 1) {
			// move the front to back
			q.pop_front();
			q.push_back(f);
		}
	}
	// returns
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> r >> c >> n >> s >> d >> h;
		memset(grid, 0, sizeof(grid));
		for (int i = 0; i < n; i++) {
			int id, hp, y, x;
			cin >> id >> hp >> y >> x;
			grid[y][x] = hp;
		}
		cout << "Case #" << t << ": " << calc() << "\n";
	}
	return 0;
}
