
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:22:25 2022
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
int n, a[N], s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i];
	}
	sort(s+1, s+1+n);
	for (int i = 1; i <= n; i++) {
		int l = 0, r = n;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (s[m] < a[i])
				l = m;
			else
				r = m-1;
		}
		cout << l << " ";
	}
	cout << "\n";
	return 0;
}
