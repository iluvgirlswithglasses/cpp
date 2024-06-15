
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Sat Jun 15 20:08:33 2024
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
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
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pi;
#define st first
#define nd second
#define aint64_t(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;

struct Eratos {

	static const int I = 1e7+7;

	int  n, cnt;
	int64_t   p[Eratos::I];	// p[i] == the i-th prime, 0-indexed
	bool e[Eratos::I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		for (int64_t i = 2; i <= n; i++) if (e[i] == 0) {
			p[cnt++] = i;
			for (int64_t j = i*i; j <= n; j+=i) e[j] = true;
		}
	}

	/**
	 * factorizing functions
	 * */
	vector<int64_t> fact(int64_t x) {
		vector<int64_t> res;
		for (int64_t _i = 0, i = p[0]; _i < cnt && i*i <= x; i = p[++_i]) {
			if (x % i == 0) {
				res.push_back(i);
				while (x % i == 0) x /= i;
			}
		}
		if (x > 1) res.push_back(x);
		return res;
	}

	map<int64_t, int> fact_map(int64_t x) {
		map<int64_t, int> res;
		for (int64_t _i = 0, i = p[0]; _i < cnt && i*i <= x; i = p[++_i]) {
			while (x % i == 0) {
				res[i]++;
				x /= i;
			}
		}
		if (x > 1) res[x]++;
		return res;
	}

	/**
	 * getting divisors functions
	 * */
	vector<int64_t> get_divisors(int64_t x) {
		int len = 1;
		vector<int64_t> res = {1};
		//
		for (int64_t _i = 0, i = p[0]; _i < cnt && i*i <= x; i = p[++_i]) if (x % i == 0) {
			int64_t t = i;
			while (x % i == 0) {
				for (int j = 0; j < len; j++)
					res.push_back(res[j] * t);
				x /= i;
				t *= i;
			}
			len = res.size();
		}
		if (x > 1) {
			for (int j = 0; j < len; j++)
				res.push_back(res[j] * x);
		}
		//
		return res;
	}
} er;

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    er.init(1e7+2);

    int64_t x; cin >> x;
    vector<int64_t> v = er.fact(x);
    vector<char> a;

    for (int64_t i: v) {
        a.push_back('A' + (i % 26));
    }
    sort(a.begin(), a.end());
    for (char c: a)
        cout << c;
    cout << "\n";

    return 0;
}

