
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 19 21:58:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

// cho tcả = nhau
// lẻ   --> sau = trc
// chẵn --> trc = sau

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n, a[N];

vector<pi> calc() {
	vector<pi> res;
	//
	int last;
	for (int i = n; i >= 1; i--) if ((a[i] % 2) == (a[1] % 2)) {
		last = i;
		break;
	}
	if (last != 1) for (int i = 1; i < last; i++) {
		if ((a[i] % 2) == (a[last] % 2)) {
			a[i] = a[last];
			res.push_back({i, last});
		}
	}
	for (int i = 2; i <= n; i++) if ((a[1] % 2) != (a[i] % 2)) {
		a[i] = a[1];
		res.push_back({1, i});
	}
	//
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << "\n";
		//
		if (n == 1)
			cout << "0\n";
		else {
			vector<pi> res = calc();
			cout << res.size() << "\n";
			for (pi &p: res)
				cout << p.st << " " << p.nd << "\n";
			cout << "\n";
		}
	}
	return 0;
}
