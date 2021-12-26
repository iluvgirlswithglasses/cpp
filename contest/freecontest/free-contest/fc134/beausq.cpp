
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec 26 18:02:06 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

#define st first
#define nd second

const int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 999};
const int S   = sizeof(P) / sizeof(P[0]) - 1;
const int N   = 2e4+7;
int loc[100];	// loc[i]: index của nguyên tố trong P

vector<int> fact(int n) {
	vector<int> res(S, 0);
	for (int i = 0, p = P[0]; p * p <= n; p = P[++i]) {
		while (n % p == 0) {
			res[i]++;
			n /= p;
		}
	}
	if (n > 1)
		res[loc[n]]++;
	return res;
}

// f[i][j]: số mũ của thừa số nguyên tố thứ j mà node i quản lý
int n, f[N<<1][S];

void add(int i, vector<int>& res) {
	for (int j = 0; j < S; j++)
		res[j] += f[i][j];
}

void build() {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < S; j++) 
			f[i][j] = f[i<<1][j] + f[i<<1|1][j];
	}
}

const char* query(int l, int r) {
	vector<int> res(S, 0);
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) add(l++, res);
		if (r&1) add(--r, res);
	}
	for (int i: res) if (i&1) return "NO";
	return "YES";
}

void upd(int i, vector<int>& v) {
	for (i+=n; i > 0; i>>=1)
	for (int j = 0; j < S; j++)
		f[i][j] += v[j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < S; i++)
		loc[P[i]] = i;
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		vector<int> m = fact(x);
		for (int j = 0; j < S; j++) {
			f[i+n][j] = m[j];
		}
	}
	build();
	//
	int q; cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			cout << query(b-1, c) << "\n";
		} else {
			vector<int> m = fact(c);
			upd(b-1, m);
		}
	}
	return 0;
}
