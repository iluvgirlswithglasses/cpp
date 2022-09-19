
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 19 23:05:32 2022
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n, x, y;	// x >= y
string a, b;
int cnta = 0, cntb = 0;

bool check() {
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') cnta++;
		if (b[i] == '1') cntb++;
	}
	return (cnta&1) == (cntb&1);
}

vector<int> strays;
vector<int> misses;

int init() {
	strays.clear();
	misses.clear();
	for (int i = 0; i < n; i++) {
		if (a[i] == '1' && b[i] == '0') strays.push_back(i);
		if (a[i] == '0' && b[i] == '1') misses.push_back(i);
	}
	//
	return 0;
}

ll prio_x() {
	
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> x >> y >> a >> b;
		if (check()) {
			init();
			cout << calc() << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}
