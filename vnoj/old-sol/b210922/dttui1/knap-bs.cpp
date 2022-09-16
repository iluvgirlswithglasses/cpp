#include <iostream>
#include <algorithm>
using namespace std;

#define u32 unsigned int

struct item {
	u32 w, v;
};

const int N = 40, H = 20;
u32 n, m, gprefix[1<<H];
item a[N], f[1<<H], g[1<<H];

/**
 * utils
 * */
int flen() {
	return 1<<(n>>1);
}

int glen() {
	return 1<<(n - (n>>1));
}

/**
 * calc
 * */
void brute(int l, int r, item t[]) {
	int len = r - l, mk = 1<<len;
	for (int i = 0; i < mk; i++) {
		for (int j = 0; j < len; j++) if (i>>j&1) 
			t[i].w += a[l+j].w, t[i].v += a[l+j].v;
	}
}

/**
 * driver
 * 
 * với K = 2**(n/2)
 * time complexity: 
 * O(K + KlogK)
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (u32 i = 0; i < n; i++) 
		cin >> a[i].w >> a[i].v;
	//
	brute(0, n>>1, f);
	brute(n>>1, n, g);
	sort(g, g+glen(), [](item &i, item &j){
		return i.w < j.w;
	});
	gprefix[0] = 0;
	for (int i = 1; i < glen(); i++) 
		// nếu xài được kết quả của entry có weight lớn hơn
		// --> cũng xài được kết quả của entry có weight nhỏ hơn
		gprefix[i] = max(g[i].v, gprefix[i-1]);
	//
	u32 res = 0;
	for (int i = 0; i < flen(); i++) if (f[i].w <= m) {
		int l = 0, r = glen() - 1;
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
