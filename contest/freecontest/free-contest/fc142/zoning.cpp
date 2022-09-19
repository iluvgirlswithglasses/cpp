
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 19 21:11:01 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int n;
ll  x;

int calc() {
	map<ll, int> m = {{0, 1}, };
	int res = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		sum += a;
		res += m[sum-x];
		m[sum]++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> x;
		int res = calc();
		if (res == 0)
			cout << "HUHU\n";
		else
			cout << res << "\n";
	}
	return 0;
}
