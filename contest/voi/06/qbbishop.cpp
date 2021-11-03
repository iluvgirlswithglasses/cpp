
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov  3 14:43:05 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <queue>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second
#define mkpair make_pair

const int N = 207;
const int I = 1e5;
int n, m, p, q, s, t;
int d[N][N];

void trans(int r, int c, int y, int x, deque<pi> &dq, int dist) {
	if (r < 0 || c < 0 || r >= n || c >= n) return;
	if (r == p && c == q) return;
	if (d[r][c] == I) return;
	if (d[r][c] != 0 && dist+1 > d[r][c]) return;
	//
	d[r][c] = dist+1;
	dq.push_back(mkpair(r, c));
	trans(r+y, c+x, y, x, dq, dist);
}

int calc() {
	deque<pi> dq; dq.push_back(mkpair(p, q));
	while (dq.size()) {
		pi u = dq.front(); dq.pop_front();
		int r = u.st, c = u.nd;
		//
		trans(r-1, c-1, -1, -1, dq, d[r][c]);
		trans(r-1, c+1, -1, +1, dq, d[r][c]);
		trans(r+1, c-1, +1, -1, dq, d[r][c]);
		trans(r+1, c+1, +1, +1, dq, d[r][c]);
	}
	if (d[s][t] == 0) return -1;
	return d[s][t];
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d %d %d %d %d", &n, &m, &p, &q, &s, &t);
	p--; q--; s--; t--;
	while (m--) {
		int r, c; scanf("%d %d", &r, &c);
		d[--r][--c] = I;
	}
	//
	if (p == s && q == t) {
		printf("0\n");
	} else {
		printf("%d\n", calc());
	}
	return 0;
}

