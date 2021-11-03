
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov  3 18:13:02 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int N = 5e4+7;
const int I = 2e9+7;
int n, p, c[N];
vector<int> v;	// v[i]: value of i-th smallest number after compress


/**
 * fenwick tree
 * */
int f[N];

void init() {
	for (int i = 0; i <= n; i++)
		f[i] = N;
}

void upd(int i, int v) {
	for (; i <= n; i += i&-i) {
		// f[i] = min(v, f[i]);
		f[i] = v < f[i] ? v : f[i];
	}
}

int get(int i) {
	int res = N;
	for (; i > 0; i -= i&-i) {
		// res = min(f[i], res);
		res = f[i] < res ? f[i] : res;
	}
	return res;
}

/**
 * calc
 * */
void compress() {
	set<int> s(c, c+1+n);	// include 0
	v.assign(s.begin(), s.end());
	for (int i = 0; i <= n; i++) {
		c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin() + 1;
	}
}

int bs(int p) {
	int l = 0, r = v.size()-1;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if (v[m] <= p) {
			l = m;
		} else {
			r = m-1;
		}
	}
	if (v[l] > p) return -1;
	return l;
}

/**
 * drivers
 * */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		c[i] += c[i-1];
	}
	//
	init();
	compress();
	//
	int res = -1;
	for (int i = 0; i <= n; i++) {
		// with a[i] == array before compress == v[ c[i] ]
		// a[i] - a[j] >= p
		// a[j] <= - p + a[i]
		int k = bs(v[ c[i]-1 ] - p) + 1;
		int j = -1;
		if (k > 0) {
			// get the smallest index of any number that have the rank <= k
			j = get(k);
			res = i-j > res ? i-j : res;
		}
		upd(c[i], i);
		// debug
		// printf("debug: i=%d j=%d k=%d a[i]=%d a[j]=%d\n", i, j, k, v[c[i]-1], v[ c[i]-1 ] - p);
	}
	printf("%d\n", res);
	return 0;
}

