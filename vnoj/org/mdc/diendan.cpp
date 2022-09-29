
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 29 22:34:19 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n, m, a[N];

bool check(int x) {
	int cnt = 1, nxt = a[0] + x;
	for (int i = 1; i < n; i++) if (a[i] >= nxt) {
		cnt++;
		nxt = a[i] + x;
	}
	return cnt >= m;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		//
		int l = 0, r = a[n-1];
		while (l < r) {
			int x = (l + r + 1) >> 1;
			if (check(x))
				l = x;
			else
				r = x-1;
		}
		cout << l << "\n";
	}
	return 0;
}
