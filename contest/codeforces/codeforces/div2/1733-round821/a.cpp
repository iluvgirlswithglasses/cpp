
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 19 21:34:28 2022
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

const int N = 107, I = 1e9+7, R = 1e9+7;
int n, k;
ll  a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//
		ll sum = 0;
		for (int i = 0; i < k; i++) {
			ll mx = 0;
			for (int j = 0; j*k + i < n; j++) {
				mx = max(mx, a[j*k + i]);
			}
			sum += mx;
		}
		cout << sum << "\n";
	}
	return 0;
}
