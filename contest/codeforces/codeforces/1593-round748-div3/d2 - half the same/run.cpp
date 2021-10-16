
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 16 13:34:13 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

const int N = 42, I = 1e6+7;
int n, a[N];

bool already_done() {
	map<int, int> m;
	for (int i = 0; i < n; i++)
		m[a[i]]++;
	for (pi p: m)
		if ((p.nd<<1) >= n) return true;
	return false;
}

void add_divisors(set<int> &k, int a) {
	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			k.insert(i);
			k.insert(a / i);
		}
	}
}

int calc() {
	if (already_done()) return -1;
	//
	set<int> k;
	for (int i = 0; i < n; i++)
	for (int j = i+1; j < n; j++)
		add_divisors(k, abs(a[i] - a[j]));
	if (k.size() == 0) return -1;
	//
	set<int>::iterator i = --k.end();
	while (true) {
		map<int, int> cnt;
		for (int j = 0; j < n; j++) {
			// a[j] += *i * (2^20)
			// đảm bảo không âm
			cnt[(a[j] + (*i<<20)) % *i]++;
		}
		for (pi p: cnt)
			if ((p.nd<<1) >= n) return *i;
		//
		if (i-- == k.begin()) break;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << calc() << "\n";
	}
	return 0;
}

