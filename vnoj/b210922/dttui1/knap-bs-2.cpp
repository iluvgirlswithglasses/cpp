
/*
superior to my previous submissions (again)
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define u32 unsigned int

struct item {
	u32 w, v;
};

const int N = 40, H = 20;
u32 n, m, fl, gl, gprefix[1<<H];
item a[N], f[1<<H], g[1<<H];

/**
 * calc
 * */
void brute(int l, int r, item t[], u32 &tl) {
	int len = r - l, mk = 1<<len;
	for (int i = 0; i < mk; i++) {
		item cr = {0, 0};
		for (int j = 0; j < len; j++) if (i>>j&1) {
			cr.w += a[l+j].w;
			cr.v += a[l+j].v;
		}
		if (cr.w <= m) t[tl++] = cr;
	}
}

/**
 * driver
 * */
void getinp() {
	u32 _n, _w, _v;
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
	brute(0, n>>1, f, fl);
	brute(n>>1, n, g, gl);
	sort(g, g+gl, [](item &i, item &j){
		return i.w < j.w;
	});
	gprefix[0] = 0;
	for (int i = 1; i < gl; i++) 
		gprefix[i] = max(g[i].v, gprefix[i-1]);
	//
	u32 res = 0;
	for (int i = 0; i < fl; i++) {
		int l = 0, r = gl - 1;
		while (l < r) {
			int mid = (l+r+1)>>1;
			if (g[mid].w + f[i].w <= m) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		//
		res = max(res, f[i].v + gprefix[l]);
	}
	//
	cout << res << "\n";
	return 0;
}
