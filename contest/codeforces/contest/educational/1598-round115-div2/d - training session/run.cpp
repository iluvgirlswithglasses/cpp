
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 10 17:05:42 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5+7;
// b[i]: số bài tập có độ khó i
int n;
// a[i]: {những độ khó sẵn có trong topic i};
// b[i]: {những topic sẵn có trong độ khó i};
set<int> a[N], b[N];
set<int> aloc, bloc;

ll case_a(set<int> a[], set<int> &loc) {
	ll res = 0;
	ll pre = 0;
	for (int i: loc) {
		res += (pre<<1) - 1;
		pre += a[i].size();
	}
	return res;
}

// x = số cách chọn khác topic
// y = số cách chọn khác độ khó
// z = số cách chọn khác cả 2
// --> calc() == x + y - z
ll calc() {
	ll res = 0;
	ll x = case_a(a, aloc),
	   y = case_a(b, bloc),
	   z = 0;
	for (int i: aloc) {
		for (int j: a[i]) {

		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int ai, bi;
			cin >> ai >> bi;
			//
			a[ai].insert(bi);
			b[bi].insert(ai);
			//
			aloc.insert(ai);
			bloc.insert(bi);
		}
		cout << calc() << "\n";
	}
	return 0;
}

