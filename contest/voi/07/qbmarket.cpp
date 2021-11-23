
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 23 15:23:56 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <cstdio>
#include <vector>
using namespace std;

/** defs */
#define u64 unsigned long long
#define st first
#define nd second

// 36 digit
struct d36 {
	static const u64 L = 1e18;
	u64 a, b;

	d36() {
		a = 0, b = 0;
	}

	void print() {
		if (a > 0)
			printf("%llu%018llu\n", a, b);
		else
			printf("%llu\n", b);
	}

	/** operators */
	d36 operator + (const d36& d) {
		d36 r = *this;
		r.a += d.a;
		r.b += d.b;
		if (r.b > L) {
			r.a++;
			r.b -= L;
		}
		return r;
	}

	d36 operator - (const d36& d) {
		d36 r = *this;
		if (r.b < d.b) {
			r.b += L;
			r.a--;
		}
		r.a -= d.a;
		r.b -= d.b;
		return r;
	}
};

/** vars */
const int N = 502, S = 1e5+7;
int n, s, c, m;
d36 f[S];

/** drivers */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	f[0].b = 1;

	scanf("%d%d", &s, &n);
	while (n--) {
		scanf("%d%d", &c, &m);
		vector<d36> g(s+1);
		// looks like I can't go in reversed order like ordinary knapsack
		// cuz I need g[i-c] and f[i-c*(m+1)] to calculate g[i]
		for (int i = c; i <= s; i++) {
			g[i] = f[i-c] + g[i-c];
			if (i >= c*(m+1)) g[i] = g[i] - f[i-c*(m+1)];
		}
		//
		for (int i = 0; i <= s; i++) {
			f[i] = f[i] + g[i];
		}
	}
	//
	f[s].print();
	return 0;
}
