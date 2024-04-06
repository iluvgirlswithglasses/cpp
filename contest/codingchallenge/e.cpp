
/*
author:		iluvgirlswithglasses
github:		https://github.com/iluvgirlswithglasses
created:	Sat Apr  6 21:45:12 2024
style:		C-Kernel with custom pointer rule
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
	https://iluvgirlswithglasses.github.io/style/cpp
I were once so into competitive programming. Now they're all gone.
BTW I love Cao Nhi.
*/

#pragma GCC optimize ("O3")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int32_t N = 1e5+7;
const int64_t I = 1e9+7, R = 1e9+7;
int64_t n, a[N];
vector<unordered_map<int64_t, int>> facts;

int __gcd(int a, int b)
{
	if (b == 0) return a;
	return __gcd(b, a % b);
}

int gcd(int a, int b)
{
	if (a > b)
		return __gcd(a, b);
	return __gcd(b, a);
}

int lcm(int a, int b)
{
	int c = gcd(a, b);
	return c * (a/c) * (b/c);
}

struct segtree
{
	int f[N << 1];

	void build()
	{
		for (int i = 0; i < n; i++)
			f[i + n] = a[i];	// factor `fact` of a[i]
		for (int i = n-1; i > 0; i--)
			f[i] = lcm(f[i<<1], f[i<<1|1]);
	}

	int query(int l, int r)
	{
		int ans = 1;
		for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if (l&1) ans = lcm(ans, f[l++]);
			if (r&1) ans = lcm(ans, f[--r]);
		}
		return ans;
	}
} st;

int64_t pow(int64_t a, int64_t b) {
	// calc a**b
	int64_t res = 1;
	while (b > 0) {
		if (b & 1) {
			res *= a;
			res %= R;
		}
		b >>= 1;
		a *= a;
		a %= R;
	}
	return res;
}

int64_t subtask1()
{
	return pow(a[0], (n + 1) * n / 2);
}

int64_t calc()
{
	st.build();
	int64_t ans = 1;
	for (int l = 0; l < n; l++) {
		for (int r = l + 1; r <= n; r++) {
			// [l:r)
			ans = (ans * st.query(l, r)) % R;
		}
	}
	return ans;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	unordered_set<int64_t> s(a, a+n);

	if (s.size() == 1)
		cout << subtask1() << "\n";
	else
		cout << calc() << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt = 1;
	while (tt--) {
		solve();
	}
	return 0;
}

