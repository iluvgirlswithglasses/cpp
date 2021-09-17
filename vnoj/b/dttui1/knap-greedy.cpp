
/*
superior to my previous submissions
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define u32 unsigned int

struct item {
	u32 w, v;
};

const int N = 40, H = 20;
u32 n, m;
vector<item> a(N), f(1<<H), g(1<<H);

void brute(int l, int r, vector<item> &t) {
	int len = r - l, mk = 1<<len, s = 0;
	//
	for (int i = 0; i < mk; i++) {
		item cr = {0, 0};
		for (int j = 0; j < len; j++) if (i>>j&1) {
			cr.w += a[l+j].w; 
			cr.v += a[l+j].v;
		}
		if (cr.w <= m) t[s++] = cr;
	}
	//
	t.resize(s);
	sort(t.begin(), t.end(), [](item &i, item &j) {
		return i.w < j.w;
	});
}

void getinp() {
	u32 _n, _w, _v; 
	//
	cin >> _n >> m;
	for (u32 i = 0; i < _n; i++) {
		cin >> _w >> _v;
		if (_w <= m) a[n++] = {_w, _v};
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();
	//
	brute(0, n>>1, f);
	brute(n>>1, n, g);
	//
	u32 res = 0, mv = 0;
	for (int i = f.size()-1, j = 0; i >= 0; i--) {
		while (j < g.size() && f[i].w + g[j].w <= m) {
			mv = max(mv, g[j++].v);
		}
		res = max(res, mv + f[i].v);
	}
	cout << res << "\n";
	return 0;
}
