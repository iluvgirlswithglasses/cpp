
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 13 15:49:49 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
ý tưởng:
do n khá nhỏ,
ta tạo chỉnh hợp dãy `n` mục tiêu
trong đó, thứ tự của mục tiêu trong dãy cũng chính là thứ tự đào mục tiêu ấy lên
ta chọn chỉnh hợp cho thời gian ngắn nhất
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

/** 
 * @ defs
 * */
#define pi pair<int, int>
#define st first
#define nd second

const int S = 504, N = 12;
const int START = 1, TARGET = 2, PATH = 3, BLOCKED = 4;
const int MOVX[] = {-1, 1, 0, 0},
          MOVY[] = {0, 0, 1, -1};

/** 
 * @ vars 
 * */
// d[i][j]: k/c tối thiểu từ i đến j
int h, w, m[S][S], d[S][S];
int targetcnt = 1;	// số mục tiêu
pi  targetloc[12];	// targetloc[0] == start pos

/**
 * @ utils
 * */
bool legit(int i, int j) {
	return i >= 0 && j >= 0 && i < h && j < w;
}

bool isblocked(int i, int j) {
	return m[i][j] == BLOCKED;
}

/**
 * @ inp
 * */
void assign(int i, int j, int t) {
	if (legit(i, j) && m[i][j] != BLOCKED)
		m[i][j] = t;
}

void getinp() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s; cin >> s;
		for (int j = 0; j < w; j++) {
			char c = s[j];
			switch (c) {
				case '@':
					assign(i, j, START);
					targetloc[0] = make_pair(i, j);
					break;
				case '!':
					assign(i, j, TARGET);
					targetloc[targetcnt++] = make_pair(i, j);
					break;
				case '.':
					assign(i, j, PATH);
					break;
				case '#':
				case '~':
					assign(i, j, BLOCKED);
					break;
				case '*':
					assign(i-1, j, BLOCKED);
					assign(i, j-1, BLOCKED);
					assign(i, j+1, BLOCKED);
					assign(i+1, j, BLOCKED);
					break;
			}
		}
	}
}

/**
 * @ perf
 * */
// tính d[i][j]
// nếu k tồn tại đường đi, return false
bool visited[S][S];

bool bfs(int src, int des) {
	int srcy = targetloc[src].st, 
	    srcx = targetloc[src].nd, 
	    desy = targetloc[des].st, 
	    desx = targetloc[des].nd;
	//
	memset(visited, false, sizeof visited);
	visited[srcy][srcx] = true;
	//
	deque<pi>  qu; qu.push_back(make_pair(srcy, srcx));
	deque<int> qd; qd.push_back(0);
	//
	while (qu.size()) {
		pi  cr   = qu.front(); qu.pop_front();
		int pred = qd.front(); qd.pop_front();
		int prey = cr.st,
		    prex = cr.nd;
		for (int m = 0; m < 4; m++) {
			int nxty = prey + MOVY[m],
			    nxtx = prex + MOVX[m],
			    nxtd = pred + 1;
			if (
				!legit(nxty, nxtx) || 
				visited[nxty][nxtx] ||
				isblocked(nxty, nxtx)
			) continue;
			// meet the destination
			if (nxty == desy && nxtx == desx) {
				d[src][des] = d[des][src] = nxtd;
				return true;
			}
			//
			visited[nxty][nxtx] = true;
			qu.push_back(make_pair(nxty, nxtx));
			qd.push_back(nxtd);
		}
	}
	return false;
}

/**
 * @ drivers
 * */
int calc_d(int* perm) {
	int n = targetcnt;
	int res = 0;
	for (int i = 0; i < n-1; i++)
		res += d[i][i+1];
	return res + d[n-1][0];
}

int calc() {
	for (int i = 0; i < targetcnt; i++)
	for (int j = i+1; j < targetcnt; j++) {
		if (!bfs(i, j)) return -1;
	}
	//
	int n = targetcnt;
	int perm[n];
	for (int i = 0; i < n; i++)
		perm[i] = i;
	//
	int best = 1e9+7;
	do {
		best = min(best, calc_d(perm));
	} while (next_permutation(perm+1, perm+n));
	//
	return best;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();
	cout << calc() << "\n";
	// debug
	int n = targetcnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}
