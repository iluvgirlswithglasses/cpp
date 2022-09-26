
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 26 19:12:09 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int n, m;
multiset<int> a;

int calc() {
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		multiset<int>::iterator p = a.upper_bound(x);
		if (p != a.begin()) a.erase(--p);
		if (a.size() == 0) return -1;
	}
	return *a.rbegin();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		a.insert(x);
	}
	cout << calc() << "\n";
	return 0;
}
