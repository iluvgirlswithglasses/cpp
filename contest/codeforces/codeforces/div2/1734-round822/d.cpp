/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 23 19:54:32 2022
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
int n, k;
ll  hp, a[N], p[N];

int cache_left;	// luôn đến được đây
int nearest_left(int r, ll &hp) {
	ll s = p[cache_left] - p[r+1];
	for (int i = min(cache_left-1, r); i >= 0; i--) {
		s += a[i];
		// không thể bò đến đây
		if (hp + s < 0) return -1;
		//
		cache_left = i;
		// đến đây được cộng máu
		// hoặc đến đây là thắng
		if (s > 0 || i == 0) {
			hp += s;
			return i;
		}
	}
	return -1;
}

int cache_right;
int nearest_right(int l, ll &hp) {
	ll s = p[cache_right] - p[l-1];
	for (int i = max(cache_right+1, l); i < n; i++) {
		s += a[i];
		// không thể bò đến đây
		if (hp + s < 0) return -1;
		//
		cache_right = i;
		// đến đây được cộng máu
		// hoặc đến đây là thắng
		if (s > 0 || i == n-1) {
			hp += s;
			return i;
		}
	}
	return -1;
}

bool calc() {
	int l = k, r = k;
	while (l != 0 && r != n-1) {
		int nl = nearest_left(l-1, hp), nr = nearest_right(r+1, hp);
		if (nl == -1 && nr == -1)
			return false;
		//
		if (nl != -1) l = nl;
		if (nr != -1) r = nr;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		hp = a[--k];
		cache_left = cache_right = k;
		//
		for (int i = k-1; i >= 0; i--)
			p[i] = a[i] + p[i+1];
		for (int i = k+1; i < n; i++)
			p[i] = a[i] + p[i-1];
		//
		if (calc())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}