
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Jan 17 07:27:23 2022
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
using namespace std;

/** 
 * @defs 
 * */
const int N = 1e5+7;
int n;
// gọi trạng thái bật/tắt cách phát [l, r] là bitmask b,
// --> dp[b][i] là số nhà ra kẹo lẻ nhiều nhất khi quét đến event i
int dp[1<<8][N<<1];
// used[i] == true --> bit i trong đoạn này đã được sử dụng
bool used[8];
// assigned[i]: bit mà cách phát [l, r] idx=i đang cầm
int assigned[N];

struct event {
	int x, idx;
	bool typ;	// 1: open, 0: close

	void set(int _x, bool _t, int _id) {
		x = _x, typ = _t, idx = _id;
	}

} e[N<<1];

/**
 * @perf
 * */
void open(int pos, int l, int r, int idx) {
	int bit;
	for (int i = 0; i < 8; i++) if (!used[i]) {
		bit = i;
		break;
	}
	used[bit] = true;
	assigned[idx] = bit;
	//
	for (int mk = 0; mk < (1<<8); mk++) {
		int state = __builtin_popcount(mk)&1, pre;
		// mask contain this bit
		// --> inherit from the corresponding previous bitset
		if ((mk>>bit)&1)
			pre = dp[mk ^ (1<<bit)][pos-1];
		// mask does not contain this bit
		// --> inherit the entire previous bitset
		else
			pre = dp[mk][pos-1];
		//
		if (pre != -1) {
			dp[mk][pos] = pre + state * (r - l);
		}
	}
}

void close(int pos, int l, int r, int idx) {
	int bit = assigned[idx];
	used[bit] = false;
	for (int mk = 0; mk < (1<<8); mk++) if (((mk>>bit)&1) == 0) {
		int state = __builtin_popcount(mk)&1;
		int pre = max(
			// inherit from the corresponding bitset that previously had this bit
			// the bit which is now turned off
			dp[mk ^ (1<<bit)][pos-1], 
			// inherit the entire previous bitset
			dp[mk][pos-1]
		);
	    //
		if (pre != -1) {
			dp[mk][pos] = pre + state * (r - l);
		}
	}
}

/**
 * @drivers
 * */
int calc() {
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	//
	for (int i = 1; i < n; i++) {
		if (e[i].typ) {
			// open
			open(i, e[i].x, e[i+1].x, e[i].idx);
		} else {
			// close
			close(i, e[i].x, e[i+1].x, e[i].idx);
		}
	}
    //
	int res = 0;
	for (int i = 0; i < (1<<8); i++) {
		res = max(res, dp[i][n-1]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		e[(i<<1)-1].set(l, 1, i);
		// if I set close type like this
		// open(l, r) and close(l, r) will have an easier time resolving conflicts
		e[i<<1].set(r+1, 0, i);
	}
	n <<= 1;
	sort(e+1, e+1+n, [](event& i, event& j){
		if (i.x == j.x)
			// close typ should be more prioritized than open typ
			// open typ: [l, r], close typ: [l:r)
			return i.typ < j.typ;
		return i.x < j.x;
	});
	//
	cout << calc() << "\n";
	return 0;
}
