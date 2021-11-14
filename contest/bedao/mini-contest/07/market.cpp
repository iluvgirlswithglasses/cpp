
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 22:08:35 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// unfinished

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define u64 unsigned long long int
const int N = 37;

u64 n, x, a[N];

vector<map<u64, int>> gen(int l, int r) {
	int len = r-l;
	u64 lim = (1<<len);
	// f[k][i]: số cách tạo tổng `i` từ `k` item
	vector<map<u64, int>> f(len+1);
	for (u64 mk = 1; mk < lim; mk++) {
		u64 k = 0, s = 0;
		for (u64 i = 0; i < n; i++) if (mk>>i&1) {
			k++;
			s += a[l+i];
		}
		f[k][s]++;
	}
	return f;
}

void prf(vector<map<u64, int>> &f) {
	for (int k = 1; k < f.size(); k++) {
		cout << k << "\n";
		for (auto pi: f[k]) {
			cout << pi.first << " " << pi.second << "\n";
		}
	}
}

u64 calc() {
	auto f = gen(0, n>>1);
	auto g = gen(n>>1, n);
	u64  res = 0;
	//
	prf(f); prf(g);
	//
	for (int k = 1; k < f.size(); k++)
	for (auto pi: f[k]) {
		u64 s = pi.first, cnt = pi.second;
		for (int kk = 1; kk < g.size(); kk++) {
			u64 target = x * (k + kk) - s;
			if (g[kk][target] > 0) res += cnt * g[kk][target];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	for (u64 i = 0; i < n; i++) cin >> a[i];
	//
	cout << calc() << "\n";
	return 0;
}

