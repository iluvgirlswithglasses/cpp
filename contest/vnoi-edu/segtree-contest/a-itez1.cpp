
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Aug 29 13:07:49 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
conclusion:
don't pay attention to these pragma lol
*/

#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <iostream>
using namespace std;

const int N = 1e5+7, I = 1e9+7;
int n, q, f[N<<1];

void build() {
	for (int i = n-1; i > 0; i--)
		f[i] = max(f[i<<1], f[i<<1|1]);
}

void upd(int i, int v) {
	f[i+=n] = v;
	for (i>>=1; i > 0; i>>=1)
		f[i] = max(f[i<<1], f[i<<1|1]);
}

int get(int l, int r) {
	int mx = -I;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) mx = max(mx, f[l++]);
		if (r&1) mx = max(mx, f[--r]);
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[i+n];
	build();
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			upd(x-1, y);
		} else {
			cout << get(x-1, y) << "\n";
		}
	}
	return 0;
}
