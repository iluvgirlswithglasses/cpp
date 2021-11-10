
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 10 12:08:49 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long
const int N = 1e6+7;
const ll  I = 1e18+7;
int n;
// p[i]: sum(a[1] -> a[i])
ll p[N];
// min suffix, max suffix of p[]
ll mins[N], maxs[N];
ll minc[N], maxc[N];
ll res, cnt;

// void prf(ll *a) {
// 	for (int i = 1; i <= n; i++) cout << a[i] << " ";
// 	cout << '\n';
// }

/**
 * utils
 */
void apply_suf(ll cr, int i, int k, ll *ms, ll *mc) {
	// k == 1  --> max
	// k == -1 --> min
	if (cr == ms[i+1])
		mc[i] = mc[i+1] + 1;
	else if (cr*k > ms[i+1]*k)
		mc[i] = 1;
	else
		mc[i] = mc[i+1];
}

void apply_res(ll cr, int c) {
	if (cr > res) {
		res = cr;
		cnt = c;
	} else if (cr == res) {
		cnt += c;
	}
}

/**
 * calc
 */
void gen_suf() {
	//
	mins[n+1] = I;
	maxs[n+1] = -I;
	for (int i = n; i >= 1; i--) {
		// sum(a[i] -> a[n]) == p[n] - p[i-1]
		ll cr = p[n] - p[i-1];
		mins[i] = min(cr, mins[i+1]);
		maxs[i] = max(cr, maxs[i+1]);
		//
		apply_suf(cr, i, -1, mins, minc);
		apply_suf(cr, i, +1, maxs, maxc);
	}
}

void calc() {
	for (int i = 1; i < n; i++) {
		//
		apply_res(abs(p[i] - mins[i+1]), minc[i+1]);
		if (maxs[i+1] != mins[i+1])
			apply_res(abs(p[i] - maxs[i+1]), maxc[i+1]);
		//
		// printf("i=%d, a=%d, b=%d, res=%d, cnt=%d\n", i, a, b, res, cnt);
	}
}

/**
 * drivers
 */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i-1];
	}
	//
	gen_suf();
	calc();
	//
	cout << res << " " << cnt << "\n";
	//
	// cout << "\ndebug\n";
	// prf(p); 
	// cout << "min:\n";
	// prf(mins); prf(minc);
	// cout << "max:\n";
	// prf(maxs); prf(maxc);
	return 0;
}

