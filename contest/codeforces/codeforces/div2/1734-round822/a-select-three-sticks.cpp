
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 23 19:04:38 2022
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

const int N = 307, I = 2e9+7, R = 1e9+7;
int n, a[N];

int calc() {
	int mn = I;
	for (int i = 0; i < n; i++)
	for (int j = i+1; j < n; j++)
	for (int k = j+1; k < n; k++) {
		mn = min(mn, (a[k] - a[j]) + (a[j] - a[i]));
	}
	return mn;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		cout << calc() << "\n";
	}
	return 0;
}
